public class PassByValue {
    public static void main(String[] args) {
        // int, long, byte, short, char, float, double, boolean, String 都是按值传递
        int a = 10;
        f(a);
        System.out.println(a);

        // 其他类型按引用传递
        Number b = new Number(5);
        g1(b);
        System.out.println(b.val);
        g2(b);
        System.out.println(b.val);

        int[] c = { 1, 2, 3, 4 };
        g3(c);
        System.out.println(c[0]);
        g4(c);
        System.out.println(c[0]);
    }

    public static void f(int a) {
        a = 0;
    }

    public static class Number {
        public int val;

        public Number(int val) {
            this.val = val;
        }
    }

    public static void g1(Number b) {
        b = null;
    }

    public static void g2(Number b) {
        b.val = 6;
    }

    public static void g3(int[] c) {
        c = null;
    }

    public static void g4(int[] c) {
        c[0] = 100;
    }
}