import java.util.logging.Logger;

public class LogTest {
        static String strClassName = LogTest.class.getName();
        static Logger LOG = Logger.getLogger(strClassName);

        private Long printLog(int num) {
                long t0, t1;
                t0 = System.nanoTime();
                for (int i = 0; i < num; i++) {
//                      LOG.info("Log test");
                        LOG.debug("Log test");
                }
                t1 = System.nanoTime();
                return t1 - t0;
        }

        public static void main(String[] args) {
                int num = Integer.parseInt(args[0]);
//              int num = 100000;
                LogTest t = new LogTest();

                long time = t.printLog(num);
                LOG.info("logging a static string " + num + " times took "
                                + time + " ns, " + (time/num) + "ns/iteration");
        }
}
