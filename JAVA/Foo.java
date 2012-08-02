public class Foo< A > {

  private A value;

  public void add(A value) {
    this.value = value;
  }

  public A get() {
    return this.value;
  }

  public static void main(String[] args) {
    Foo< Integer > fooInt = new Foo< Integer >();
    fooInt.add(1000);
    System.out.println("Value is : "+ fooInt.get());
  }
}

