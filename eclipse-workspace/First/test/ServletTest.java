import static org.junit.Assert.*;

import org.junit.Test;

public class ServletTest
{

	MyServlet servlet;
	@Test
	public void test() {
 	servlet = new MyServlet();
	Integer result = servlet.add(new Integer(2), new Integer(2));
	assertEquals(result, new Integer(4));
	}

}
