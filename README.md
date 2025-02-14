# NGO and Needy Person Help System

This project is a desktop application developed using **Qt** (C++) to create a help network where two types of users interact: **NGO** and **Needy Person**. The system allows Needy Persons to send emergency help requests to NGOs, who can then view and respond to these requests. The communication between clients and the server is done using **TCP/IP networking**, with server-side data storage handled by **SQLite**.

The system also includes a **login and signup** feature, where users can register their details, log in, and send/receive messages.

## Features
- **Two types of users**: 
  - **NGO**: Receives messages/requests from needy users.
  - **Needy Person**: Can request help in case of a medical emergency.
- **Networking**: 
  - Server is built using `QTcpServer` to handle multiple clients.
  - Server uses TCP connections and listens on a specific port (`1234`).
  - Communication between clients (NGOs and Needy Persons) is done via TCP sockets.
- **Message handling**: 
  - Needy users' emergency messages are sent to NGOs and stored in a database.
  - If an NGO isn't connected when a request is made, the message is stored for later delivery.
- **Login and Signup**:
  - Users can **sign up** and **log in**.
  - **Signup** includes storing the user's data (username, password, type of user).
  - **Login** checks credentials from the database and allows access based on the user type (NGO/Needy).
- **Database**: SQLite database is used to store:
  - User data (username, password, user type).
  - Emergency messages and their statuses.

## Requirements
- **Qt 5.12+** (with Qt Network module)
- **SQLite** database
