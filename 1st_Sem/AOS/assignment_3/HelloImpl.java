import java.sql.*; 
import java.util.*;  

public class HelloImpl implements Hello {  
   
   public List<Student> getStudents() throws Exception {

        // JDBC driver name and database URL 
        String JDBC_DRIVER = "com.mysql.jdbc.Driver";   
        String DB_URL = "jdbc:mysql://localhost:3306/65G";  
        String USER = "root"; 
        String PASS = "1234";  

        Connection conn = null; 
        Statement statement = null;  
        List<Student> list = new ArrayList<Student>(); 
        try{
            //Register JDBC driver , mariadb is a dropin open source replacement for mysql.
            Class.forName("com.mysql.jdbc.Driver");   

            System.out.println("Connecting to a selected database..."); 
            conn = DriverManager.getConnection(DB_URL, USER, PASS); 
            System.out.println("Connected");  

          
            System.out.println("Quering......"); 
            statement = conn.createStatement();  
            String query = "SELECT * FROM student_data"; 
            ResultSet result = statement.executeQuery(query); 
            
            while(result.next()) { 
                int id  = result.getInt("id"); 
                String name = result.getString("name"); 
                String branch = result.getString("branch"); 
                int percentage = result.getInt("percentage"); 
                String email = result.getString("email");  
            
                Student student = new Student(id, name, branch, percentage,email);
                list.add(student); 
            } 
            result.close();  
        } catch(Exception e){
            System.out.println(e.getMessage());
        }
        return list;  
   }  
}
