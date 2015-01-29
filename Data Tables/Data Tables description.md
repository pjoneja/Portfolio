# Data Tables
A borrowed/adapted implementation of an HTML data table that leverages the power and ease-of-use of Google Spreadsheets. My implementation uses JSON, JavaScript, HTML Tables and Google Spreadsheets.

### What it looks like:
![online](https://github.com/pjoneja/Portfolio-Showcase/blob/master/Data%20Tables/TableWebsite.png)
![online](https://github.com/pjoneja/Portfolio-Showcase/blob/master/Data%20Tables/TableGSheet.png)
![online](https://github.com/pjoneja/Portfolio-Showcase/blob/master/Data%20Tables/TableWithHTML.png)

### Further Notes:
* Use CONCAT() function in GSheets to concatenate the contents of multiple cells in the spreadsheet. This follows the "don't-repeat-yourself (DRY)" principle, as frequently repeated phrases like the size/margin of HTML table is handled automatically.
* Use Data Validation feature in GSheets to provide a dropdown list of options for the contents of cells. For example, this could be W, L, -, or even a button that links to the live stream. These are the only options, so using a dropdown list saves time and prevents errors in a high-stress environment (eg. updating the site live from the sidelines of the basketball game)
* Leverage basic spreadsheet functions to add the number of wins/losses and point totals.

### Future improvements: 
* HTML Tables can be "prettier" by CSS without adding any complications to this JSON-parsing function.
