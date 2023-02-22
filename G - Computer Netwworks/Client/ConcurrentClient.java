import java.net.*;
import java.io.*;
public class ConcurrentClient
{
	private Socket socket = null;
	private DataInputStream input = null;
	private DataInputStream in = null;
	private DataOutputStream out = null;
	public ConcurrentClient(String address, int port)
	{
		try
		{
			socket = new Socket(address, port);
			System.out.println("Connected");
			input = new DataInputStream(System.in);
			in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
			out = new DataOutputStream(socket.getOutputStream());
		}
		catch(UnknownHostException u)
		{
			System.out.println(u);
		}
		catch(IOException i)
		{
			System.out.println(i);
		}
		String line = "";
		while (! line.equals("Over"))
		{
			try
			{
				System.out.print("To server: ");
				line = input.readLine();
				out.writeUTF(line);
				System.out.print("From server: ");
				line = in.readUTF();
				System.out.println(line);
			}
			catch(IOException i)
			{
				System.out.println(i);
			}
		}
		try
		{
			input.close();
			in.close();
			out.close();
			socket.close();
		}
		catch(IOException i)
		{
			System.out.println(i);
		}
	}
	public static void main(String args[])
	{
		ConcurrentClient client = new ConcurrentClient("127.0.0.1", 5000);
	}
}
