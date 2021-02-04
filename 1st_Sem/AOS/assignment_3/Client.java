import java.rmi.registry.LocateRegistry; 
import java.rmi.registry.Registry; 
import java.util.*;  

public class Client {  
    private Client() {}  
    public static void main(String[] args)throws Exception {  
        try { 
            Registry registry = LocateRegistry.getRegistry(null); 
            Hello stub = (Hello) registry.lookup("Hello"); 

            // Calling the remote method using the obtained object 
            List<Student> list = (List)stub.getStudents(); 
            for (Student s:list) { 
            System.out.println("Id: " + s.getId() + ",  Name: " + s.getName() + ",  Branch: " + s.getBranch() + ",  Percent: " + s.getPercent() + ",  Email: " + s.getEmail() + "\n"); 
            }  
        // System.out.println(list); 
        } catch (Exception e) { 
            System.err.println("Client exception: " + e.toString()); 
            e.printStackTrace(); 
        } 
    } 
}
