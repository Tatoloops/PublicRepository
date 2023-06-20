package tatoloops.learningpacks.view;

class FrameInformation {
    private static final int FRAME_WIDTH=256;
    private static final int FRAME_HEIGHT=256;
    private static final int FRAME_BORDER_HEIGHT=20;
    private static final int FRAME_BORDER_WIDTH=20;
    private static final String ICON_PATH="Assets//LearningPack02.png";

    public static int getFRAME_WIDTH() {
        return FRAME_WIDTH;
    }

    public static int getFRAME_HEIGHT() {
        return FRAME_HEIGHT;
    }

    public static int getFRAME_BORDER_HEIGHT() {
        return FRAME_BORDER_HEIGHT;
    }

    public static int getFRAME_BORDER_WIDTH() {
        return FRAME_BORDER_WIDTH;
    }

    public static String getICON_PATH() {
        return ICON_PATH;
    }
}
