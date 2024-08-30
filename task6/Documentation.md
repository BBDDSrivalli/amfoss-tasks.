## Documentation for Expense Tracker Fullstack

### Overview

The **Expense Tracker Fullstack** project includes a backend and frontend for managing expenses and incomes. The backend is built with **Node.js** and **Express**, while the frontend is created using **React.js**. This documentation provides an overview of the project’s functionality and implementation details.

### Functionality

#### Models

- **ExpenseModel.js**

    - `ExpenseModel.create(title, amount, date, category)`
        - Creates a new expense with the specified details.

    - `ExpenseModel.findAll()`
        - Retrieves all expenses from the database.

    - `ExpenseModel.findById(id)`
        - Retrieves a specific expense by its ID.

    - `ExpenseModel.update(id, updates)`
        - Updates an existing expense with new values.

    - `ExpenseModel.delete(id)`
        - Deletes an expense by its ID.

- **IncomeModel.js**

    - `IncomeModel.create(title, amount, date, category)`
        - Creates a new income record.

    - `IncomeModel.findAll()`
        - Retrieves all income records.

    - `IncomeModel.findById(id)`
        - Retrieves a specific income by its ID.

    - `IncomeModel.update(id, updates)`
        - Updates an existing income record.

    - `IncomeModel.delete(id)`
        - Deletes an income record by its ID.

#### Controllers

- **expense.js**
    - Handles requests related to expenses, including creation, retrieval, update, and deletion.

- **income.js**
    - Manages income-related requests, similar to expense operations.

#### Views

- **Dashboard**
    - Displays a summary of expenses and incomes using charts and graphs.

- **ExpenseForm**
    - Provides a form for adding and editing expenses.

- **IncomeForm**
    - Provides a form for adding and editing incomes.

### Implementation Details

#### Expense Management

Expenses are managed through a series of forms and views. The backend API handles CRUD operations for expenses, while the frontend interacts with these endpoints to provide a user interface for managing transactions.

#### Income Management

Similar to expenses, incomes are managed through dedicated forms and views. The frontend communicates with the backend to perform necessary operations and display income details.

### Code Example

Here’s a snippet from the `app.js` file showing the setup of the Express server and routes:

```javascript
const express = require('express');
const app = express();
const expenseRoutes = require('./routes/transactions');

app.use(express.json());
app.use('/api/transactions', expenseRoutes);

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});


