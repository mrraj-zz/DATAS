class Cross {

  public static void main(String[] args) {
    System.out.println("New interface");
    CrossInterface cross = new CrossClass();
    System.out.println("Addition is : "+ cross.add(1,3));
  }
}

interface CrossInterface {

  public int add(int v1, int v2);
}

class CrossClass implements CrossInterface {

  public int add(int v1, int v2) {
    return(v1+v2);
  }
}
