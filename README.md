# datx
A command line tool that allows to parse CSV files by category!

## Usage
- Input file CSV (.datx) path as parameter
- The utility will output the parsed .datx file to the console

## Creation of CSV/.datx files
- Take any .csv file and add a new line to the very beginning
- On that line add the category names (like `username,email,password` but it can have any amount of categories)
- So the first CSV element is the username, the next is the email, the third is the password and it repeats.

## Example .datx file
```
username,email,password
johndoe,johndoe@email.com,pazz123
micheall,mscott@email2.net,test123
```
Usernames: `johndoe`, `micheall`<br>
Emails: `johndoe@email.com`, `mscott@email2.net`<br>
Passwords: `pazz123`, `test123`

