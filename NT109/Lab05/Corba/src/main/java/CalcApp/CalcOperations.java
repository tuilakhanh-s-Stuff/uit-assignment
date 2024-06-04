package CalcApp;


/**
 * Generated from IDL interface "Calc".
 *
 * @author JacORB IDL compiler V 3.9
 * @version generated at May 25, 2024 2:17:24 PM
 */

public interface CalcOperations
{
	/* constants */
	/* operations  */
	float sum(float a, float b);
	float div(float a, float b) throws CalcApp.CalcPackage.DivisionByZero;
	float mul(float a, float b);
	float sub(float a, float b);
}
