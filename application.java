import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public abstract class Student implements Serializable, Displayable {
    private String name;
    private int id;
    private List<Course> courses;

    public Student(String name, int id) {
        this.name = name;
        this.id = id;
        this.courses = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public List<Course> getCourses() {
        return courses;
    }

    public void addCourse(Course course) {
        courses.add(course);
    }

    public abstract String getStudentType();

    @Override
    public void display() {
        System.out.println("Name: " + name + ", ID: " + id + ", Type: " + getStudentType());
        courses.forEach(Course::display);
    }
}


public class UndergraduateStudent extends Student {
    public UndergraduateStudent(String name, int id) {
        super(name, id);
    }

    @Override
    public String getStudentType() {
        return "Undergraduate";
    }
}


public class GraduateStudent extends Student {
    public GraduateStudent(String name, int id) {
        super(name, id);
    }

    @Override
    public String getStudentType() {
        return "Graduate";
    }
}


import java.io.Serializable;

public class Course implements Serializable, Displayable {
    private String courseName;
    private int credits;

    public Course(String courseName, int credits) {
        this.courseName = courseName;
        this.credits = credits;
    }

    public String getCourseName() {
        return courseName;
    }

    public int getCredits() {
        return credits;
    }

    @Override
    public void display() {
        System.out.println("Course: " + courseName + ", Credits: " + credits);
    }
}


public interface Displayable {
    void display();
}


import java.io.Serializable;

public class Grade implements Serializable {
    private Course course;
    private String grade;

    public Grade(Course course, String grade) {
        this.course = course;
        this.grade = grade;
    }

    public Course getCourse() {
        return course;
    }

    public String getGrade() {
        return grade;
    }

    @Override
    public String toString() {
        return "Course: " + course.getCourseName() + ", Grade: " + grade;
    }
}


import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class StudentManagementSystem {
    private static List<Student> students = new ArrayList<>();
    private static final String FILE_NAME = "students.dat";
    private static ExecutorService executorService = Executors.newFixedThreadPool(5);

    public static void main(String[] args) {
        loadStudents();
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
            System.out.println("1. Add Student");
            System.out.println("2. Remove Student");
            System.out.println("3. Display Students");
            System.out.println("4. Save and Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    addStudent(scanner);
                    break;
                case 2:
                    removeStudent(scanner);
                    break;
                case 3:
                    displayStudents();
                    break;
                case 4:
                    saveStudents();
                    exit = true;
                    break;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }

        scanner.close();
        executorService.shutdown();
    }

    private static void addStudent(Scanner scanner) {
        System.out.print("Enter student name: ");
        String name = scanner.next();
        System.out.print("Enter student ID: ");
        int id = scanner.nextInt();
        System.out.print("Enter student type (1. Undergraduate, 2. Graduate): ");
        int type = scanner.nextInt();

        Student student;
        if (type == 1) {
            student = new UndergraduateStudent(name, id);
        } else if (type == 2) {
            student = new GraduateStudent(name, id);
        } else {
            System.out.println("Invalid type. Student not added.");
            return;
        }

        System.out.print("Enter number of courses: ");
        int courseCount = scanner.nextInt();
        for (int i = 0; i < courseCount; i++) {
            System.out.print("Enter course name: ");
            String courseName = scanner.next();
            System.out.print("Enter course credits: ");
            int credits = scanner.nextInt();
            Course course = new Course(courseName, credits);
            student.addCourse(course);
        }

        students.add(student);
        System.out.println("Student added successfully.");
    }

    private static void removeStudent(Scanner scanner) {
        System.out.print("Enter student ID to remove: ");
        int id = scanner.nextInt();
        students.removeIf(student -> student.getId() == id);
        System.out.println("Student removed successfully.");
    }

    private static void displayStudents() {
        students.forEach(student -> executorService.execute(student::display));
    }

    private static void loadStudents() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(FILE_NAME))) {
            students = (List<Student>) ois.readObject();
        } catch (FileNotFoundException e) {
            System.out.println("No existing data found. Starting fresh.");
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error loading student data: " + e.getMessage());
        }
    }

    private static void saveStudents() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILE_NAME))) {
            oos.writeObject(students);
            System.out.println("Student data saved successfully.");
        } catch (IOException e) {
            System.out.println("Error saving student data: " + e.getMessage());
        }
    }
}
