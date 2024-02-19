# <p align = "center">Minitalk</p>

<p align = "center">
<a href = https://github.com/Adamsandlerisgod><img minitalk = "minitalk" src = "./docs/minitalke.png"></a></p>

**Mandatory Part - Communication Program Design:**

**Client-Server Architecture:**
This project entails the development of a communication program featuring a client and a server.

**Server Initialization:** 
Begin by launching the server, which will print its unique Process ID (PID) for reference.

**Client Parameters:**
The client operation requires two parameters: the server's PID and the string intended for transmission.

**String Transmission:**
The client's primary task is to send the specified string parameter to the server.

**Prompt Server Display:**
Upon receiving the string, the server promptly prints its content.

**Efficient String Display:**
The server's string display operation must be swift; a delay exceeding 1 second for 100 characters is considered inefficient.

**Scalability and Efficiency Considerations:**

**Prompt Server Response:**
The server must exhibit quick string display, with a benchmark of 1 second for displaying 100 characters. Delays beyond this indicate potential inefficiency.

**Continuous Server Operation:** Ensure the server can seamlessly handle successive string receptions from multiple clients without requiring a restart.

**Exclusive UNIX Signal Communication:**
The communication channel between the client and server is restricted to UNIX signals.

**Signal Utilization:**
Only SIGUSR1 and SIGUSR2 signals are permissible. Note that Linux does not queue signals of the same type if pending.

**Bonus Part - Additional Features:**

**Acknowledgment Mechanism:** 
As a bonus feature, the server acknowledges each received message by sending a signal back to the client.

**Unicode Support:**
For enhanced versatility, this project supports Unicode characters, providing an extended range of communication possibilities.
