import java.util.*;
 
public class DISCSPro {
 public static void main(String[] args) {
  Scanner in = new Scanner(System.in);
  // input
  int numWords = in.nextInt();
  int numWords2 = in.nextInt();
  int shift = in.nextInt()%26; in.nextLine();
  String wordSet = in.nextLine();
  String tegami = in.nextLine();
  // encrypting tegami
  StringBuilder sb = new StringBuilder();
  for( int i = 0; i < tegami.length(); i++ ) {
   if( tegami.charAt(i) != ' ' )
    sb.append(encrypt(tegami.charAt(i),shift));
   else sb.append(" ");
  }
  // encrypted tegami
  String encrypted = sb.toString();
  // counting available characters
  int[] charCount = new int['z'+1];
  char c = '?';
  for( int i = 0; i < wordSet.length(); i++ ) {
   c = wordSet.charAt(i);
   if( c != ' ' ) charCount[c]++;
  }
  // subtracting characters needed
  String s = "Make her kokoro go doki-doki!";
  for( int i = 0; i < encrypted.length(); i++ ) {
   c = encrypted.charAt(i);
   if( c != ' ') {
    if( charCount[c] > 0 ) charCount[c]--;
    else {
     s = "It is gonna be daijoubu.";
     break;
    }
   }
  }
  System.out.println(s);
 }
 
 // method for encrypting
 public static char encrypt( char c, int shift ) {
  if( c+shift > 'z' ) return (char) (c+shift-26);
  return (char) (c+shift);
 }
}// Test gym
