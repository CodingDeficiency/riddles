package weatherpkg;

public class PredictorTester {

	public static void main(String[] args) {

		Predictor myPredictor = new Predictor();
		System.out.println(myPredictor.getDay(new DayStats(8,8,2016)));
		System.out.println(myPredictor.getDay(new DayStats(8,8,2015)));
		System.out.println(myPredictor.predictDay(8,8,2015));
		System.out.println(myPredictor.predictAverageDailyTemp(8,8,2015));
		System.out.println(myPredictor.predictAverageDailyTemps(8,8,2015,10));
		
	}
}
