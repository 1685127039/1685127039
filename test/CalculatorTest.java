import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

public class CalculatorTest {
    @Test
    public void MidToLastTest()
    {
        Calculator calculator=new Calculator();
        List<String> list=Arrays.asList("10.580×(94-38)-(8.8440-(37.7-55))","(46+12.377)+22.2×91×(86.268+(76.12-74.5))","27.9-(39.4+36.8÷(79.827-8.360))",
        "56÷(11-(13-25×(26.0+47-76)+23))","(49÷0.095-38.8584)-21.70+(9+30.3)","16.35-(59×(73×49.4241)+32.19)÷(26-(69.50×29))","70.5÷76","13.318+12÷4×60.2×83.94");
        for(String str:list)
        {
            System.out.println(calculator.MidtoLast(str));
        }
    }
    @Test
    public void getResult()
    {
        Calculator calculator=new Calculator();
        List<String> list=Arrays.asList("10.580×(94-38)-(8.8440-(37.7-55))","(46+12.377)+22.2×91×(86.268+(76.12-74.5))","27.9-(39.4+36.8÷(79.827-8.360))",
                "56÷(11-(13-25×(26.0+47-76)+23))","(49÷0.095-38.8584)-21.70+(9+30.3)","16.35-(59×(73×49.4241)+32.19)÷(26-(69.50×29))","70.5÷76","13.318+12÷4×60.2×83.94");
        for(String str:list)
        {
            System.out.println(calculator.getResult(calculator.MidtoLast(str)));
        }
    }
}
