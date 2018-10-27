import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
 
public class SHA
{
 
    /**
     * @param args
     * @throws NoSuchAlgorithmException 
     */
    public static void main(String[] args) throws NoSuchAlgorithmException {
        System.out.println(sha1("sanket"));
    }
     
    static String sha1(String input) throws NoSuchAlgorithmException {
        MessageDigest mDigest = MessageDigest.getInstance("SHA1");
        byte[] result = mDigest.digest(input.getBytes());
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < result.length; i++) {
            sb.append(Integer.toString((result[i] & 0xff) + 0x100, 16).substring(1));
        }
         
        return sb.toString();
    }
}

/*Output:
Message digest: 
 Used Algorithm =SHA1
 Provider for the algorithm =SUN version 1.8
 Convert it toString =SHA1 Message Digest from SUN, <initialized>

SHA1("") = DA39A3EE5E6B4B0D3255BFEF95601890AFD80709
SHA1("abcd") = 81FE8BFE87576C3ECB22426F8E57847382917ACF
SHA1("1234567890") = 01B307ACBA4F54F55AAFC33BB06BBBF6CA803E9A
*/
