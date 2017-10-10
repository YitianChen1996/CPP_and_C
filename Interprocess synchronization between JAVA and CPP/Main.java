import java.io.*;

public class Main {

    public static File lockFile, dataFile;

    public static void writeUnlock() {
        try {
            lockFile = new File("mutex.txt");
            BufferedWriter out = new BufferedWriter(new FileWriter("mutex.txt"));
            out.write("1");
            out.flush();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public static void writerLock() {
        while (true) {
            lockFile = new File("mutex.txt");
            try {
                InputStreamReader reader = new InputStreamReader(new FileInputStream(lockFile));
                BufferedReader br = new BufferedReader(reader);
                String line;
                line = br.readLine();
                if (!line.equals("2")) {
                    System.out.println("open file failed\n");
                    Thread.sleep(500);
                    continue;
                } else {
                    BufferedWriter out = new BufferedWriter(new FileWriter("mutex.txt"));
                    out.write("2");
                    out.flush();
                    out.close();
                    break;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }

    public static void main(String[] args) {
        try {
            int cnt=0;
            while(true){
                writerLock();
                dataFile = new File("data.txt");
                BufferedWriter out = new BufferedWriter(new FileWriter("data.txt"));
                for (int i=0;i<=4;i++){
                    cnt++;
                    System.out.println("writing");
                    out.write("I am writing "+ cnt);
                }
                out.flush();
                out.close();
                writeUnlock();

            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
