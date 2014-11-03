package processing.app;

import static processing.app.I18n._;

import java.awt.Graphics;
import java.awt.Image;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;

import javax.swing.JComponent;

public class ToolButtonImage extends JComponent implements ToolButtonMetrics {
  private static final long serialVersionUID = 1L;

  /**
   * For Each Button:
   */
  ButtonID id;
  String title;
  String description;

  int imageFilePosition;

  Image stateImage[];

  // .. .. .. .. .. .. .. .. .. .. .. ..

  static boolean isLoaded = false;

  // .. .. .. .. .. .. .. .. .. .. .. ..

  static Map<ButtonID, ToolButtonImage> buttonIdMap;
  // static List<ToolButton> buttonList;

  static ToolButtonImage BtnVerify = new ToolButtonImage(ButtonID.RUN,
      _("Verify"), _("Verify"), 0);
  static ToolButtonImage BtnExport = new ToolButtonImage(ButtonID.EXPORT,
      _("Upload"), _("Upload Using Programmer"), 1);
  static ToolButtonImage BtnNew = new ToolButtonImage(ButtonID.NEW, _("New"),
      _("New Editor Window"), 2);
  static ToolButtonImage BtnOpen = new ToolButtonImage(ButtonID.OPEN,
      _("Open"), _("Open in Another Window"), 3);
  static ToolButtonImage BtnSave = new ToolButtonImage(ButtonID.SAVE,
      _("Save"), _("Save"), 4);
  static ToolButtonImage BtnSerial = new ToolButtonImage(ButtonID.SERIAL,
      _("Serial Monitor"), _("Serial Monitor"), 5);

  // .. .. .. .. .. .. .. .. .. .. .. ..

  static {
    buttonIdMap = new HashMap<ButtonID, ToolButtonImage>();

    buttonIdMap.put(ButtonID.RUN, BtnVerify);
    buttonIdMap.put(ButtonID.EXPORT, BtnExport);
    buttonIdMap.put(ButtonID.NEW, BtnNew);
    buttonIdMap.put(ButtonID.OPEN, BtnOpen);
    buttonIdMap.put(ButtonID.SAVE, BtnSave);
    buttonIdMap.put(ButtonID.SERIAL, BtnSerial);
  }

  // .. .. .. .. .. .. .. .. .. .. .. ..

  public ToolButtonImage(ButtonID id, String title, String descr, int imagePos) {
    this.id = id;
    this.title = title;
    this.description = descr;
    this.imageFilePosition = imagePos;

    stateImage = new Image[StateCOUNT];
  }

  // .. .. .. .. .. .. .. .. .. .. .. ..
  public static boolean isLoaded() {
    return isLoaded;
  }

  public static int getButtonCount() {
    return buttonIdMap.size();
  }

  public static ToolButtonImage getById(ButtonID id) {
    return buttonIdMap.get(id);
  }

  // .. .. .. .. .. .. .. .. .. .. .. ..

  public String getTitle() {
    return title;
  }

  public String getDescription() {
    return description;
  }

  public static int getImageHeight() {
    return ButtonHEIGHT;
  }

  public static int getImageWidth() {
    return ButtonWIDTH;
  }

  static protected void loadButtons(EditorToolbar owner) {
    if (isLoaded())  return;
    
    Image allButtons = Base.getThemeImage("buttons.gif", owner);

    Iterator<Entry<ButtonID, ToolButtonImage>> buttons = buttonIdMap.entrySet()
        .iterator();

    while (buttons.hasNext()) {
      Entry<ButtonID, ToolButtonImage> btnEntry = buttons.next();
      ToolButtonImage button = btnEntry.getValue();

      button.stateImage = new Image[StateCOUNT];

      for (int state = 0; state < StateCOUNT; state++) {
        Image image = owner.createImage(getImageWidth(), getImageHeight());
        Graphics g = image.getGraphics();

        g.drawImage(allButtons, -(button.imageFilePosition * ButtonImageHW) -
            StateCOUNT, (-2 + state) * ButtonImageHW, null);

        button.stateImage[state] = image;
      }
    }

    isLoaded = true;
  }

  public ButtonID getId() {
    return id;
  }

  public Image getStateImage(State state) {
    switch (state) {
    case INACTIVE:
      return stateImage[0];
    case ROLLOVER:
      return stateImage[1];
    case ACTIVE:
      return stateImage[2];
    default:
    }

    return null;
  }

};
