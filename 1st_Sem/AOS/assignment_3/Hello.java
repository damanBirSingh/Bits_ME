import java.rmi.Remote; 
import java.rmi.RemoteException; 
import java.util.*;

// Remote interface 
public interface Hello extends Remote {  
    public List<Student> getStudents() throws Exception;  
}
