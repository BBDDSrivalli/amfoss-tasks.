Overview of the Code
This is a python based Telegram bot made using the python-telegram-bot library.
users can browse books by genre, manage their personal bookshelf, and view details about books.
It uses the Google Books API to fetch book information and manages data through CSV files and Word documents.

Downloads and Descriptions
1. python-telegram-bot:

Description: A library to interact with the Telegram Bot API. It provides a high-level interface for creating Telegram bots.
Purpose: Used to handle communication between the bot and Telegram servers, manage updates, and handle user interactions.
2. requests:
Description: A simple HTTP library for Python. It is used to make HTTP requests.
Purpose: Fetches data from the Google Books API by making HTTP GET requests.
3. python-dotenv:

Description: A library to load environment variables from a .env file.
Purpose: Loads API keys and tokens from environment variables for security.
4. docx:

Description: A library to create and modify Word documents.
Purpose: Generates and manipulates Word documents for saving and sending users’ reading lists.
5. csv:

Description: A built-in Python module for handling CSV (Comma-Separated Values) files.
Purpose: Stores book information in a CSV format for easy viewing and downloading.



Code Explanation
1. Imports and Setup
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
->import os: Provides functions to interact with the operating system (e.g., file handling).
->import csv: For reading and writing CSV files.
->import requests: For making HTTP requests.
->from telegram...: Imports classes from python-telegram-bot for bot operations.
->from dotenv import load_dotenv: For loading environment variables from a .env file.
->from docx import Document: For creating and managing Word documents

2. Constants and Global Variables
```python

TELEGRAM_TOKEN = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
BOOKS_API_KEY = "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY"

GENRES = [
    "Adventure", "Fantasy", "Mystery", "Romance", "Science Fiction",
    "Thriller", "Non-fiction", "Historical", "Horror", "Biography"
]

user_bookshelf = {}
```

Aaaaaaand I read that API's should not be shared so...
->TELEGRAM_TOKEN and BOOKS_API_KEY: Store the API tokens for Telegram and Google Books API.
->GENRES: A list of book genres for users to choose from.
->user_bookshelf: A dictionary to keep track of books added by each user.

3. Conversation States
```python

CHOOSE_GENRE, GET_BOOK_TITLE, HANDLE_SHELF = range(3)
```
-->Defines conversation states for managing user interactions:
   ->CHOOSE_GENRE: When the user selects a genre.
   ->GET_BOOK_TITLE: When the user provides a book title.
   ->HANDLE_SHELF: When the user interacts with their bookshelf.
4. Command Handlers

Start Command
```python
async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
    welcome_message = (
        "Hi there, I'm Page Pal, your friendly bookworm buddy!\n"
        "I’m here to help you find awesome books and keep track of your reading adventures!\n"
        "You can start by typing /browse to explore book genres or /myshelf to manage your personal bookshelf."
    )
    await update.message.reply_text(welcome_message)
```
Purpose: Sends a welcome message when the /start command is invoked.
update.message.reply_text(welcome_message): Sends the welcome message to the user.

Browse Genres Command

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

Sure! Let’s delve deeper into the code, focusing on the functions and their detailed workings, and how they interact with each other.

Detailed Code Explanation
1. Imports and Setup
python
Copy code
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
import os: For interacting with the operating system (e.g., file handling).
import csv: For creating and reading CSV files.
import requests: For making HTTP requests to fetch data from APIs.
from telegram import ...: Imports necessary classes to handle messages and inline buttons.
from telegram.ext import ...: Imports classes for building the bot, handling commands, and managing conversations.
from dotenv import load_dotenv: To load environment variables from a .env file.
from docx import Document: To create and manipulate Word documents.
2. Constants and Global Variables
python
Copy code
TELEGRAM_TOKEN = "7532229434:AAHO1RK7iNlO9dxlKNhYKnu7V_sBAiK4_-U"
BOOKS_API_KEY = "AIzaSyBx27rgeFfi_5ToJwqJRCGGUwh5T_X-__I"

GENRES = [
    "Adventure", "Fantasy", "Mystery", "Romance", "Science Fiction",
    "Thriller", "Non-fiction", "Historical", "Horror", "Biography"
]

user_bookshelf = {}
TELEGRAM_TOKEN and BOOKS_API_KEY: Store API tokens for Telegram and Google Books API.
GENRES: A list of genres that the bot can offer.
user_bookshelf: A dictionary that tracks the books added by each user.
3. Conversation States
python
Copy code
CHOOSE_GENRE, GET_BOOK_TITLE, HANDLE_SHELF = range(3)
CHOOSE_GENRE: State for when the user selects a genre.
GET_BOOK_TITLE: State for when the user provides a book title to add or remove from their bookshelf.
HANDLE_SHELF: State for handling actions related to the user’s bookshelf (add, remove, view).
4. Command Handlers
Start Command

python
Copy code
async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
    welcome_message = (
        "Hi there, I'm Bookie, your friendly bookworm buddy! 🐛📚\n"
        "I’m here to help you find awesome books and keep track of your reading adventures!\n"
        "You can start by typing /browse to explore book genres or /myshelf to manage your personal bookshelf."
    )
    await update.message.reply_text(welcome_message)
Purpose: Sends a welcome message when the /start command is used.
update.message.reply_text(welcome_message): Sends the welcome message to the user.
Browse Genres Command

python
Copy code
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

->Purpose: Displays a list of book genres with buttons for each genre.
->InlineKeyboardButton(genre, callback_data=genre.lower()): Creates buttons for each genre with callback_data set to the genre’s lowercase version.
->InlineKeyboardMarkup(genre_buttons): Creates a keyboard layout with the genre buttons.
->await update.message.reply_text(...): Sends the message with genre buttons to the user.
->return CHOOSE_GENRE: Sets the state to CHOOSE_GENRE.

Show Books Command

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
->Purpose: Fetches books for the selected genre, creates a CSV file with book details, and sends it to the user.
->fetch_books_by_genre(genre): Calls a function to get book data based on the genre.
->filename = f"{genre}_books.csv": Creates a filename based on the genre.
->with open(filename, 'w', newline='', encoding='utf-8') as csvfile: Opens a file for writing CSV data.
->writer.writerow(...): Writes the header and book details to the CSV file.
->with open(filename, 'rb') as file: Opens the file in binary read mode to send it as a document.
->await query.message.reply_document(document=file): Sends the file to the user.
->os.remove(filename): Deletes the file after sending.
->await query.message.reply_text(...): Sends a message asking if the user wants to browse another genre.

5. 5. Fetching Book Data

Fetching Books by Genre
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
->Purpose: Retrieves book information from Google Books API based on the genre.
->url = f"https://www.googleapis.com/books/v1/volumes?q=subject:{genre}&key={BOOKS_API_KEY}": Constructs the API request URL.
->response = requests.get(url).json(): Sends the GET request and parses the JSON response.
->response.get("items", []): Retrieves the list of books from the response.
->item.get("volumeInfo", {}): Extracts volume information for each book.
->book_list.append([...]): Appends book details to the list.

Fetching Preview Link
```python
def fetch_preview_link(book_title):
    url = f"https://www.googleapis.com/books/v1/volumes?q={book_title}&key={BOOKS_API_KEY}"
    response = requests.get(url).json()
    items = response.get("items", [])

    if items:
        return items[0].get("volumeInfo", {}).get("previewLink")
    return None
```
->Purpose: Retrieves the preview link for a specific book title.
->url = f"https://www.googleapis.com/books/v1/volumes?q={book_title}&key={BOOKS_API_KEY}": Constructs the API request URL for a book title.
->response = requests.get(url).json(): Sends the GET request and parses the JSON response.
->items[0].get("volumeInfo", {}).get("previewLink"): Retrieves the preview link for the first book in the response.

6. Bookshelf Management
Managing the Bookshelf
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

->Purpose: Displays options for managing the user's bookshelf.
->if user_id not in user_bookshelf:: Initializes an empty bookshelf for new users.
->buttons = [...]: Creates buttons for adding, removing, and viewing books.
->InlineKeyboardMarkup(buttons): Creates a keyboard layout with the management options.
->await update.message.reply_text(...): Sends the management options to the user.

Handling Bookshelf Actions:

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
->Purpose: Handles the user’s bookshelf actions based on their choice.
->context.user_data['action']: Stores the user’s action (add/remove) to process in the modify_shelf function.
->await query.message.reply_text(...): Sends messages based on user actions.
->doc = Document(): Creates a new Word document for viewing the bookshelf.
->doc.add_heading(...): Adds a heading to the document.
->doc.add_paragraph(...): Adds book details and preview links to the document.
->doc.save(doc_filename): Saves the document with a filename.
->with open(doc_filename, 'rb') as file: Opens the document in binary read mode to send it.
->os.remove(doc_filename): Deletes the document file after sending.

Adding/Removing Books
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
->Purpose: Adds or removes books from the user's bookshelf based on the action specified.
->user_bookshelf[user_id].append(book_title): Adds the book to the user’s bookshelf.
->user_bookshelf[user_id].remove(book_title): Removes the book from the user’s bookshelf if it exists.

7. Main Function
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
->Purpose: Sets up the bot with the necessary handlers and starts polling for updates.
->ApplicationBuilder().token(TELEGRAM_TOKEN).build(): Creates an instance of the bot application with the given token.
->ConversationHandler(...): Manages the different conversation states and their handlers.
->app.add_handler(...): Adds command and conversation handlers to the bot.
->app.run_polling(): Starts the bot and keeps it running to handle incoming messages.











