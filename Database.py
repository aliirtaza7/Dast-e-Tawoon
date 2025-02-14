import sqlite3

# Connect to the existing SQLite database
conn = sqlite3.connect("needyperson.db")

# Create a cursor object to execute SQL commands
cursor = conn.cursor()

# Delete the record with id = 1 from the receive_messages table
cursor.execute("DELETE FROM ngo WHERE NgoName = 989968657")

# Commit the changes to the database
conn.commit()

# Close the connection
conn.close()

print("Record with id = 1 deleted successfully.")
