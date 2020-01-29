

import java.awt.geom.Area;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/welcome")
public class MyServlet extends HttpServlet implements Servlet 
{
	double pi = 3.14;
	double squaredResult;
	double area = 0;
	private static final long serialVersionUID = 1L;
       
    
	
	
    public MyServlet()
    {
        super();
        // TODO Auto-generated constructor stub
    }
    
    

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		// TODO Auto-generated method stub
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		// Kofi's code
		
		Double num1 = new Double(request.getParameter("num1"));
		Double num2 = new Double(request.getParameter("num2"));

		Integer result;
		result = add(num1,num2);
		double area;
		area = calcAreaOfCirc1(6);
		
		PrintWriter out = response.getWriter();
		out.println("<html>");
		out.println("<body>");
		out.println("<h1>The result equals: " + result + "</h1>");
		out.println("<h1>The area of a circle is: " + area + "</h1>");
		out.println("<h1>Hello World!</h1>");
		out.println("</body>");
		out.println("</html>");
	
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
	{
		// TODO Auto-generated method stub
		doGet(request, response);
	}
	
	public double add( double x, double y)
	{
		return x + y;
	}
	
	public double calcAreaOfCirc1(int diameter)
	{
        squaredResult = Math.pow(diameter/2, 2);
        double area = squaredResult * pi;
        return area;
	}
	
	public double calcAreaOfCirc2(Double radius)
	{
        squaredResult = Math.pow(radius, 2);
        return squaredResult * pi;
	}
	
	public double calcAreaOfCirc3(Double diameter)
	{
        squaredResult = Math.pow(diameter/2, 2);
        return squaredResult * pi;
	}

}
