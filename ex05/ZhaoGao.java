//文件名：ZhaoGao.java
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

public class ZhaoGao {
    public static void main(String[] args) {
	ArrayList pen = new ArrayList();
        pen.add(new Horse("Bai-Long"));
        pen.add(new Deer("Mei-Hua"));
        System.out.println(((Horse)pen.get(0)).name());
        System.out.println(((Horse)pen.get(1)).name()); // 指鹿为马！
    }
}