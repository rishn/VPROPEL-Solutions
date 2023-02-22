import java.net.*;
import java.io.*;
public class IterativeServer
{
	private Socket socket = null;
	private ServerSocket server = null;
	private DataInputStream input = null;
	private DataInputStream in = null;
	private DataOutputStream out = null;
	public IterativeServer(int port)
	{
		int count = 1, flag = 1;
		try
		{
			server = new ServerSocket(port);
			System.out.println("Server started\nWaiting for a client ...");
			while (true)
			{
				socket = server.accept();
				System.out.println("Client accepted");
				String line = "";	
				in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            	out = new DataOutputStream(socket.getOutputStream());
            	input = new DataInputStream(System.in);
				while (!line.equals("Over"))
            	{
           			System.out.printf("From client %d: ", count);
                	line = in.readUTF();
					if (line.equals("Over"))
					{
						count++;
						flag = 0;
						break;
					}
                	System.out.println(line);
					System.out.printf("To client %d: ", count);
					line = input.readLine();
                	out.writeUTF(line);
            	}
				if (flag == 1)
					count++;
            	in.close();
            	out.close();
				System.out.print("Closing connection...");
				socket.close();
			}
		}
		catch(IOException i)
		{
			System.out.println(i);
		}
	}
	public static void main(String args[])
	{
		IterativeServer server = new IterativeServer(5000);
	}
}