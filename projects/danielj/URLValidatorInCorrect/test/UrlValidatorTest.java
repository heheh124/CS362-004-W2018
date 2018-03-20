//INCORRECT URL VALIDATOR

import junit.framework.TestCase;
import java.util.Random;
//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {
	// private boolean printStatus = false;
	// private boolean printIndex = false;
	private static final long timeStop = 60 * 500; 
	private static final int NUM_TESTS = 100;
	
	public UrlValidatorTest(String testName) {
		super(testName);
   }

   public void testManualTest()
   {
	   //You can use this function to implement your manual testing	   
	   //http://commons.apache.org/proper/commons-validator/apidocs/org/apache/commons/validator/routines/UrlValidator.html
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Alter URL
	   System.out.println("Test URLs:\n");
	   System.out.println(urlVal.isValid("http://www.google.com")); //True
	   System.out.println(urlVal.isValid("htp:/www.google.com")); //False
	   System.out.println(urlVal.isValid("hp:/www.google.com"));  //False
	   System.out.println(urlVal.isValid("ftp:/www.google.com")); //False
	   System.out.println(urlVal.isValid("hsdf:/www.google.com")); //False
	   System.out.println(urlVal.isValid("http://wxy.google.com")); //False
	   System.out.println(urlVal.isValid("http://www.google.xyz")); //False
	   // System.out.println(urlVal.isValid("htt://www.google.com")); //False - Error
	   // System.out.println(urlVal.isValid("https://www.google.com")); //True - Error
	   
   }
   String[] validScheme = new String[] {"http://", "ftp://", "https://"};
   String[] validAuthority = new String[] {"www.amazon.com", "amazon.au", "255.255.255.255"};
   String[] validPort = new String[] {":80", ":65555", ":0", ""};
   String[] validPath = new String[] {"/check", "/564543", "/check/", "", "/check/class"};
   
   String[] invalidScheme = new String[] {"3ht://", "http:/", "http/", "://", "", "h4t://"};
   String[] invalidAuthority = new String[] {"amazon.dfwqe", "", "bdc", "2.4.6.7.8"};
   String[] invalidPort = new String[] {":asdf", "80fdaa", ":-3"};
   String[] invalidPath = new String[] {"//check", "/check//class", "/.../"};
   
   String[] query = new String[] {"", "?action=view"};
 
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   
	   long timeStart = System.currentTimeMillis();
	   long timeTotal = System.currentTimeMillis() - timeStart;
		UrlValidator urlVal = new UrlValidator();
		
		for(int iteration = 0; timeTotal < timeStop; iteration++) {
			Random rand = new Random(System.currentTimeMillis());
			
			for (int i = 0; i < NUM_TESTS; i++) {
				int scheme = rand.nextInt(2) + 0;
				int auth = rand.nextInt(2) + 0;
				int port = rand.nextInt(3) + 0;
				int path = rand.nextInt(4) + 0;
				int q = rand.nextInt(1) + 0;
				String URL = validScheme[scheme] + validAuthority[auth] + validPort[port] + validPath[path] + query[q];

				assertTrue(URL, urlVal.isValid(URL));
				
		}

		timeTotal = (System.currentTimeMillis() - timeStart);
		
		if((iteration%10000)==0 && iteration!=0)
			System.out.println("Total time: " + timeTotal + " of " + timeStop);
		}
   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   
	   long timeStart = System.currentTimeMillis();
		long timeTotal = System.currentTimeMillis() - timeStart;	
		UrlValidator urlVal = new UrlValidator();

		for(int iteration = 0; timeTotal < timeStop; iteration++) {
			Random rand = new Random(System.currentTimeMillis());
			
			for (int i = 0; i < NUM_TESTS; i++) {
				int scheme = rand.nextInt(5) + 0;
				int auth = rand.nextInt(3) + 0;
				int port = rand.nextInt(2) + 0;
				int path = rand.nextInt(2) + 0;
				int q = rand.nextInt(1) + 0;
				String URL = invalidScheme[scheme] + invalidAuthority[auth] + invalidPort[port] + invalidPath[path] + query[q];

				assertFalse(URL, urlVal.isValid(URL)); 
			}

			timeTotal = (System.currentTimeMillis() - timeStart);
	 
			if((iteration % 10000) == 0 && iteration!= 0)
				System.out.println("Total time: " + timeTotal + " of " + timeStop);
		}
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //ALodge
	   System.out.print("Hello from testIsValid\n");
	   long allowAllSchemes = 1;
	   UrlValidator validator = new UrlValidator(null, null, allowAllSchemes);
	   String query = "http://www.cnn.com";
	   boolean result;
	   char[] charArray = query.toCharArray();
	   for (int x = 0; x < charArray.length; x++)
	   {
		   // modify one character in the array
		   charArray[x] = '&';
		   String query_mod = new String(charArray);
		   try 
		   {
			   result = validator.isValid(query_mod);
			   // assertEquals(true, validator.isValid("http://www.google.com"));
			   // first = true;
		   }
		   catch(Exception e) 
		   {
			   // first = false;
			   System.out.print("In catch\n");
			   result = false;
		   }

		   // print the results
		   System.out.print(query_mod);
		   System.out.print(": ");
		   System.out.print(result);
		   System.out.print("\n");
		   
		   charArray = query.toCharArray();
	   }
	   
	   //JamesD
	   //You can use this function for programming based testing
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   UrlValidator urlVal2 = new UrlValidator(null, null, UrlValidator.ALLOW_LOCAL_URLS);
	   
	   String url;
	   
	   String[] validScheme = {"http://", "ftp://", "h3t://", ""};
	   String[] validAuthority = {"www.google.com", "go.com", "0.0.0.0", "255.255.255.255", "255.com", "go.cc"};
	   String[] validPort = {":80", ":65535", ":0", "", ":49152"};
	   String[] validPath = {"/test1", "/t123", "/$23", "/test1/", "", "/test1/file"};
	   String[] validLocal = {"http://localhost/", "http://machine/"};
	  
	   int counter = 0;
	   int failCounter = 0;
	   int schemeFlag = 0, authFlag = 0, portFlag = 0;
	   
	   System.out.println("\n----------------------------");
	   System.out.println("Test all valid URL parts:");
	   System.out.println("----------------------------");
  
	   for (int a = 0 ; a < validScheme.length; a++) {
		   for (int b = 0; b < validAuthority.length; b++) {
			   for (int c = 0; c < validPort.length; c++) {
				   for (int d = 0; d < validPath.length; d++) {
					   url = validScheme[a] + validAuthority[b] + validPort[c] + validPath[d];
					
					   // set flags
					   if (d == 0 && c == 1) {
						   portFlag = 1;}
					 
					   if (c == 0 && b == 1) {
						   authFlag = 1;}
					   
					   if (b == 0 && a == 1) {
						   schemeFlag = 1;}
					   
					   // test case based on flags being set
					   if (portFlag == 0 && authFlag == 0 && schemeFlag == 0) {
						   System.out.println("\nTest Case #" + (counter + 1) + ": Path Validation");
						   } else if (portFlag == 1 && authFlag == 0 && schemeFlag == 0) {
						   System.out.println("\nTest Case #" + (counter + 1) + ": Port Validation");
					   } else if (authFlag == 1 && schemeFlag == 0) {
						   System.out.println("\nTest Case #" + (counter + 1) + ": Authority Validation");
						  } else {
						   System.out.println("\nTest Case #" + (counter + 1) + ": Scheme Validation");
					   }
					   
					   // print whether the case passed or failed
					   if (urlVal.isValid(url) == true) {
						   System.out.println("Valid URL, test case PASSED: " + url);
						   } else {
						   System.out.println("Invalid URL, test case FAILED: " + url);
						   failCounter++;}
					   counter++;
				
				   }
			   }
		   }
	   }
	   
   }


	public static void main(String[] argv) {
		System.out.print("Hello from main\n");
	
		UrlValidatorTest test1 = new UrlValidatorTest("testUrl");
		test1.testManualTest();
		
		UrlValidatorTest test2 = new UrlValidatorTest("testUrl");
		test2.testIsValid();
		
		System.out.print("Goodbye from main\n");
	}
}
