import java.lang.String;
class Strg
{
  public static void main(String args[])
  {
    String s1=new String("msrit banglore");
    String s2="MSRIT BANGLORE";
    System.out.println("the string s1 is:"+s1);
    System.out.println("the string s2 is:"+s2);
    System.out.println("length of string is:"+s1.length());
    System.out.println("first acc of r is at pos:"+s1.indexOf('r'));
    System.out.println("string in uppercase:"+s1.toUpperCase());
    System.out.println("string in lowercase:"+s1.toLowerCase());
    System.out.println("s1 equal to s2:"+s1.equals(s2));
    System.out.println("s1 equals ignore case to s2:"+s1.equalsIgnoreCase(s2));
    int result=s1.compareTo(s2);
    System.out.println("after compareTO()");
    if(result==0)
      System.out.println(s1+"equals to"+s2);
    else if(result>0)
      System.out.println(s1+"is greater than to"+s2);
    else
      System.out.println(s1+"is smaller than to"+s2);
    System.out.println("char at the index of 6 is:"+s1.charAt(6));
    String s3=s1.substring(4,12);
    System.out.println("extracted subString is:"+s3);
    System.out.println("after replacing with a s1:"+s1.replace('r','a'));
    String s4="   this is a book   ";
    System.out.println("the string s4 is:"+s4);
    System.out.println("after trim():"+s4.trim());
  }
}