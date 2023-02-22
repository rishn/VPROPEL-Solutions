class MultithreadingDemo implements Runnable
{
        int a, b, c, thread;
        public MultithreadingDemo(int t, int i, int j)
        {
                a = i;
                b = j;
                thread = t;
        }
        public void run()
        {
                try
                {
                        int chk, j, i = a;
                        if (thread == 1)
                        {
                                while(i < b)
                                {
                                        chk = 1;
                                        System.out.println("Thread " + Thread.currentThread().getId() + " is running");
                                        for (j = 2; j < i; j++)
                                                if (i % j == 0)
                                                {
                                                        chk = 0;
                                                        break;
                                                }
                                        if (chk == 1) 
                                                System.out.println("Thread " + Thread.currentThread().getId() + " says prime = " + i);
                                        Thread.sleep(10);
                                        i++;
                                }
                        }
                        else if (thread == 2)
                        {
                                while(i < b)
                                {
                                        System.out.println("Thread " + Thread.currentThread().getId() + " is running");
                                        if (i % 2 != 0)
                                                System.out.println("Thread " + Thread.currentThread().getId() + " says odd = " + i);
                                        Thread.sleep(10);
                                        i++;
                                }
                        }

                }
                catch (Exception e)
                {
                        System.out.println("Exception is caught");
                }
        }
}
public class Multithread
{
        public static void main(String[] args)
        {
                try
                {
                        MultithreadingDemo md1=new MultithreadingDemo(1, 10, 20);
                        MultithreadingDemo md2=new MultithreadingDemo(2, 100, 200);
                        Thread t1 = new Thread(md1);
                        Thread t2 = new Thread(md2);
                        t1.start();
                        t2.start();
                }
                catch(Exception e)
                {
                        System.out.println("Exception is caught");
                }
        }
}
