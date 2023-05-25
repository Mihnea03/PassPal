# PassPal

&emsp;PassPal is the perfect, lightweight password manager for people that want to save their passwords in a secure and fast manner!

&emsp;To build the app, you have to run the 'init.sh' script in your terminal. After the script is finished, you can start the app by running the command 'make && make run'. If the app is already created, you can run 'make run' anytime to start it.

## Folder meaning

* __src__: Contains all source code files
* __bin__: Contains the passpal binary executable
* __obj__: Contains all object files
* __.users__: All user files will be created in this folder
* __.user_meta__: File that contains required metadata for every user: the username and the encrypted password

## How it works

&emsp;Every time a user is created, a new, unique private key is assigned and written in the users file. When a user tries to log in, the input is verified by comparing the encrypted password in the metadata file with the resulting new encrypted password created from the input and the private key of the user.

## Available commands

When first starting the app, the main menu offers 3 different options:
* __Log In__: Input username and password to log in and gain access to all passwords of the user
* __Sign Up__: Create a new account and log in automatically
* __Delete Account__: Delete account given as input only if the input information is correct

To quit PassPal, press 'q' at any time


After logging in, the user has 6 operations they can do:
* __Add password__: Add an URL and a password to the account
* __Delete password__: Delete an URL and its password from the account
* __See password by URL__: Print a password by its URL to the command line
* __See passwords__: Print all passwords to the command line
* __Export passwords__: Print all passwords to a given file
* __Clear all passwords__: Delete all URLs and passwords from the account


