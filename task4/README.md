## Overview of the Code

This is a Python-based Telegram bot made using the python-telegram-bot library. Users can browse books by genre, manage their personal bookshelf, and view details about books. It uses the Google Books API to fetch book information and manages data through CSV files and Word documents.

---

## Downloads and Descriptions

1. **python-telegram-bot**:
   - **Description**: A library to interact with the Telegram Bot API. It provides a high-level interface for creating Telegram bots.
   - **Purpose**: Used to handle communication between the bot and Telegram servers, manage updates, and handle user interactions.

2. **requests**:
   - **Description**: A simple HTTP library for Python. It is used to make HTTP requests.
   - **Purpose**: Fetches data from the Google Books API by making HTTP GET requests.

3. **python-dotenv**:
   - **Description**: A library to load environment variables from a .env file.
   - **Purpose**: Loads API keys and tokens from environment variables for security.

4. **docx**:
   - **Description**: A library to create and modify Word documents.
   - **Purpose**: Generates and manipulates Word documents for saving and sending users’ reading lists.

5. **csv**:
   - **Description**: A built-in Python module for handling CSV (Comma-Separated Values) files.
   - **Purpose**: Stores book information in a CSV format for easy viewing and downloading.

---

## Code Explanation

1. **Imports and Setup**:
    ```python
    import os
    import csv
    import requests
    from telegram import Update, InlineKeyboardButton, InlineKeyboardMarkup
    from telegram.ext import (
        ApplicationBuilder, CommandHandler, MessageHandler, CallbackQueryHandler,
        ConversationHandler, ContextTypes, filters
    )
    from dotenv import load_dotenv
    from docx import Document
    ```
   - `import os`: Provides functions to interact with the operating system (e.g., file handling).
   - `import csv`: For reading and writing CSV files.
   - `import requests`: For making HTTP requests.
   - `from telegram...`: Imports classes from python-telegram-bot for bot operations.
   - `from dotenv import load_dotenv`: For loading environment variables from a .env file.
   - `from docx import Document`: For creating and managing Word documents.

2. **Constants and Global Variables**:
    ```python
    TELEGRAM_TOKEN = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    BOOKS_API_KEY = "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY"

    GENRES = [
        "Adventure", "Fantasy", "Mystery", "Romance", "Science Fiction",
        "Thriller", "Non-fiction", "Historical", "Horror", "Biography"
    ]

    user_bookshelf = {}
    ```
   - `TELEGRAM_TOKEN` and `BOOKS_API_KEY`: Store the API tokens for Telegram and Google Books API.
   - `GENRES`: A list of book genres for users to choose from.
   - `user_bookshelf`: A dictionary to keep track of books added by each user.

3. **Conversation States**:
    ```python
    CHOOSE_GENRE, GET_BOOK_TITLE, HANDLE_SHELF = range(3)
    ```
   - Defines conversation states for managing user interactions:
     - `CHOOSE_GENRE`: When the user selects a genre.
     - `GET_BOOK_TITLE`: When the user provides a book title.
     - `HANDLE_SHELF`: When the user interacts with their bookshelf.

4. **Command Handlers**:
   - **Start Command**:
     ```python
     async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
         welcome_message = (
             "Hi there, I'm Page Pal, your friendly bookworm buddy!\n"
             "I’m here to help you find awesome books and keep track of your reading adventures!\n"
             "You can start by typing /browse to explore book genres or /myshelf to manage your personal bookshelf."
         )
         await update.message.reply_text(welcome_message)
     ```
     - **Purpose**: Sends a welcome message when the /start command is invoked.

   - **Browse Genres Command**:
     ```python
     async def browse_genres(update: Update, context: ContextTypes.DEFAULT_TYPE):
         genre_buttons = [
             [InlineKeyboardButton(genre, callback_data=genre.lower())] for genre in GENRES
         ]
         reply_markup = InlineKeyboardMarkup(genre_buttons)
         await update.message.reply_text(
             "Yay! Let's find some books! 📖\nPick a genre that tickles your fancy:",
             reply_markup=reply_markup
         )
         return CHOOSE_GENRE
     ```
     - **Purpose**: Displays a list of book genres with buttons for each genre.

   - **Show Books Command**:
     ```python
     async def show_books(update: Update, context: ContextTypes.DEFAULT_TYPE):
         query = update.callback_query
         genre = query.data
         books = fetch_books_by_genre(genre)
         
         if books:
             filename = f"{genre}_books.csv"
             with open(filename, 'w', newline='', encoding='utf-8') as csvfile:
                 writer = csv.writer(csvfile)
                 writer.writerow(["Title", "Authors", "Description", "Published Date", "Preview Link"])
                 for book in books:
                     writer.writerow(book)
             
             with open(filename, 'rb') as file:
                 await query.message.reply_document(document=file)
             
             os.remove(filename)
         else:
             await query.message.reply_text("Oops! I couldn't find any books in that genre. 😢")
         
         await query.message.reply_text("Want to explore another genre? Just type /browse again!")
         return ConversationHandler.END
     ```
     - **Purpose**: Fetches books for the selected genre, creates a CSV file with book details, and sends it to the user.

5. **Fetching Book Data**:
   - **Fetching Books by Genre**:
     ```python
     def fetch_books_by_genre(genre):
         url = f"https://www.googleapis.com/books/v1/volumes?q=subject:{genre}&key={BOOKS_API_KEY}"
         response = requests.get(url).json()
         book_list = []

         for item in response.get("items", []):
             info = item.get("volumeInfo", {})
             title = info.get("title", "Unknown")
             authors = ", ".join(info.get("authors", []))
             description = info.get("description", "No description available.")
             published_date = info.get("publishedDate", "N/A")
             preview_link = info.get("previewLink", "No preview available.")
             book_list.append([title, authors, description, published_date, preview_link])

         return book_list
     ```
     - **Purpose**: Retrieves book information from Google Books API based on the genre.

   - **Fetching Preview Link**:
     ```python
     def fetch_preview_link(book_title):
         url = f"https://www.googleapis.com/books/v1/volumes?q={book_title}&key={BOOKS_API_KEY}"
         response = requests.get(url).json()
         items = response.get("items", [])

         if items:
             return items[0].get("volumeInfo", {}).get("previewLink")
         return None
     ```
     - **Purpose**: Retrieves the preview link for a specific book title.

6. **Bookshelf Management**:
   - **Managing the Bookshelf**:
     ```python
     async def my_shelf(update: Update, context: ContextTypes.DEFAULT_TYPE):
         user_id = update.message.from_user.id
         if user_id not in user_bookshelf:
             user_bookshelf[user_id] = []

         buttons = [
             [InlineKeyboardButton("Add a Book 📚", callback_data='add')],
             [InlineKeyboardButton("Remove a Book 🗑️", callback_data='remove')],
             [InlineKeyboardButton("View My Bookshelf 👀", callback_data='view')]
         ]
         reply_markup = InlineKeyboardMarkup(buttons)
         await update.message.reply_text(
             "What would you like to do with your bookshelf today?",
             reply_markup=reply_markup
         )
         return HANDLE_SHELF
     ```
     - **Purpose**: Displays options for managing the user's bookshelf.

   - **Handling Bookshelf Actions**:
     ```python
     async def handle_shelf(update: Update, context: ContextTypes.DEFAULT_TYPE):
         query = update.callback_query
         user_id = query.from_user.id

         if query.data == 'add':
             await query.message.reply_text("What’s the title of the book you want to add? 📖")
             context.user_data['action'] = 'add'
             return GET_BOOK_TITLE

         elif query.data == 'remove':
             if not user_bookshelf[user_id]:
                 await query.message.reply_text("Your bookshelf is empty! Nothing to remove. 😅")
                 return ConversationHandler.END

             await query.message.reply_text("Which book would you like to remove? 🗑️")
             context.user_data['action'] = 'remove'
             return GET_BOOK_TITLE

         elif query.data == 'view':
             if not user_bookshelf[user_id]:
                 await query.message.reply_text("Your bookshelf is empty! Start adding some books! 📚")
             else:
                 doc = Document()
                 doc.add_heading('My Cute Little Bookshelf', level=1)

                 for book in user_bookshelf[user_id]:
                     link = fetch_preview_link(book)
                     doc.add_paragraph(f"{book} - Preview: {link or 'No preview available'}")

                 doc_filename = 'bookshelf.docx'
                 doc.save(doc_filename)
                 with open(doc_filename, 'rb') as file:
                     await query.message.reply_document(document=file)
                 os.remove(doc_filename)

             return ConversationHandler.END
     ```
     - **Purpose**: Handles the user’s bookshelf actions based on their choice.

   - **Adding/Removing Books**:
     ```python
     async def modify_shelf(update: Update, context: ContextTypes.DEFAULT_TYPE):
         user_id = update.message.from_user.id
         book_title = update.message.text

         if context.user_data.get('action') == 'add':
             user_bookshelf[user_id].append(book_title)
             await update.message.reply_text(f"'{book_title}' is now snugly placed on your bookshelf! 📚")
         elif context.user_data.get('action') == 'remove':
             if book_title in user_bookshelf[user_id]:
                 user_bookshelf[user_id].remove(book_title)
                 await update.message.reply_text(f"'{book_title}' has been taken off your bookshelf! 🗑️")
             else:
                 await update.message.reply_text(f"Couldn't find '{book_title}' on your bookshelf. 🤔")
         return ConversationHandler.END
     ```
     - **Purpose**: Adds or removes books from the user's bookshelf based on the action specified.

7. **Main Function**:
    ```python
    def main():
        app = ApplicationBuilder().token(TELEGRAM_TOKEN).build()

        conv_handler = ConversationHandler(
            entry_points=[
                CommandHandler('browse', browse_genres),
                CommandHandler('myshelf', my_shelf),
            ],
            states={
                CHOOSE_GENRE: [CallbackQueryHandler(show_books)],
                GET_BOOK_TITLE: [MessageHandler(filters.TEXT & ~filters.COMMAND, modify_shelf)],
                HANDLE_SHELF: [CallbackQueryHandler(handle_shelf)],
            },
            fallbacks=[CommandHandler('start', start)]
        )

        app.add_handler(CommandHandler('start', start))
        app.add_handler(conv_handler)

        print("Bookie is up and ready to recommend books!")
        app.run_polling()
    ```
   - **Purpose**: Sets up the bot with the necessary handlers and starts polling for updates.
