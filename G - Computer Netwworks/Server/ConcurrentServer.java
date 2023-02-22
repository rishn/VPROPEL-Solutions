import java.net.*;
import java.io.*;
class ThreadDemo implements Runnable
{
	private DataInputStream in = null;
    private DataOutputStream out = null;
	private DataInputStream input = null;
	private Socket s;
	ThreadDemo(Socket s)
	{
		this.s = s;
	}
	public void run()
	{
		String line = "";
		try
		{	
			in = new DataInputStream(new BufferedInputStream(s.getInputStream()));
            out = new DataOutputStream(s.getOutputStream());
            input = new DataInputStream(System.in);
			while (!line.equals("Over"))
            {
           		System.out.print("From client: ");
                line = in.readUTF();
				if (line.equals("Over"))
					break;
                System.out.println(line);
				System.out.print("To client: ");
				line = input.readLine();
                out.writeUTF(line);
            }
            in.close();
            out.close();
			System.out.print("Closing connection...");
			s.close();
		}
		catch(IOException i)
        {
            System.out.println(i);
    	}
	}
}
public class ConcurrentServer
{
	private Socket socket = null;
	private ServerSocket server = null;
	public ConcurrentServer(int port)
	{
		try
		{
			server = new ServerSocket(port);
			System.out.println("Server started\nWaiting for a client ...");
			while (true)
			{
				socket = server.accept();
				System.out.println("Client accepted");
				ThreadDemo td = new ThreadDemo(socket);
				Thread t = new Thread(td);
				t.start();
			}
		}
		catch(IOException i)
		{
			System.out.println(i);
		}
	}
	public static void main(String args[])
	{
		ConcurrentServer server = new ConcurrentServer(5000);
	}
}

