import org.junit.jupiter.api.Test;

public class QuestionerTest {
    @Test
    public void pareQuestion()
    {
        Questioner questioner=new Questioner();
        for(int i=0;i<10;i++) System.out.println(questioner.questionWithParentheses(true,50));
        for(int i=0;i<10;i++) System.out.println(questioner.questionWithParentheses(false,50));
        for(int i=0;i<10;i++) System.out.println(questioner.questionWithParentheses(true,100));
        for(int i=0;i<10;i++) System.out.println(questioner.questionWithParentheses(false,100));
    }

    @Test
    public void withoutPareQuestion()
    {
        Questioner questioner=new Questioner();
        for(int i=0;i<10;i++) System.out.println(questioner.questionWithoutParentheses(true,50));
        for(int i=0;i<10;i++) System.out.println(questioner.questionWithoutParentheses(false,50));
        for(int i=0;i<10;i++) System.out.println(questioner.questionWithoutParentheses(true,100));
        for(int i=0;i<10;i++) System.out.println(questioner.questionWithoutParentheses(false,100));
    }
}
