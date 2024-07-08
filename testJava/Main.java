package testJava;

public class Main {
    public static void main(String[] args) {
        Test test = new Test();
        // 调用Test类的成员函数
        test.createNewNumber();
        int result = test.sum(1, 2);
        System.out.println("Sum = " + result);
        
    }
}
