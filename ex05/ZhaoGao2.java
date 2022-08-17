//文件名：ZhaoGao2.java
import java.util.*;

class Horse {
    private String name;
    public Horse(String name) {this.name = name;}
    public String name() {return this.name;}
}

class Deer {
    private String name;
    public Deer(String name) {this.name = name;}
    public String name() {return this.name;}
}

public class ZhaoGao2 {
    public static void main(String[] args) {
        // 一个有约束的泛型容器
        ArrayList<Horse> pen = new ArrayList<Horse>(); // 指定圈中只能存取马
        pen.add(new Horse("Bai-Long"));
        pen.add(new Horse("Chi-Tu"));
        // pen.add(new Deer("Mei-Hua")); //不能再将鹿放入圈内
        System.out.println(pen.get(0).name()); // 无须再进行强制类型转换
        System.out.println(pen.get(1).name()); // 同上
    }
}