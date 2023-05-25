# PassPal

&emsp;PassPal is the perfect, lightweight password manager for people that want to save their passwords in a secure and fast manner!

&emsp;To build the app, you have to run the 'init.sh' script in your terminal. After the script is finished, you can start the app by running the command 'make && make run'. If the app is already created, you can run 'make run' any time to start it.

## Folder meaning

* __src__: Contains all source code files
* __bin__: Contains the passpal binary executable
* __obj__: Contains all object files
* __.users__: All user files will be created in this folder
* __.user_meta__: File that contains required metadata for every user: the username and the encrypted password

## How it works

&emsp;Every time a user is created, a new, unique private key is assigned and written in the users file. When a user tries to log in, the input is verified by comparing the encrypted password in the metadata file with the resulting new encrypted password from the input and the key of the user.

