package processing.app;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;

class ToolButton implements ToolButtonMetrics {
  private ButtonID id;
  private ToolButtonImage image;
  private State state;

  private int toolbarPosition;
  private int gap;
  private boolean isRightJustified;

  private Boundary boundary;
  private int helpTextX;

  public ToolButton(ButtonID id) {
    image = ToolButtonImage.getById(this.id = id);
    boundary = new Boundary(new Range(0, 0), new Range(0, ButtonHEIGHT));
    toolbarPosition = 0;
    gap = 0;
    helpTextX = 0;
    isRightJustified = false;
    setState(State.INACTIVE);
  }

  public ToolButton(ButtonID id, int gap) {
    this(id);
    this.gap = gap;
  }

  public ToolButton(ButtonID id, boolean isRightJustified) {
    this(id);
    this.isRightJustified = isRightJustified;
  }

  public ToolButtonImage getImage() {
    return image;
  }

  public boolean isRightJustified() {
    return isRightJustified;
  }

  public int getGap() {
    return gap;
  }

  public void setXRange(final Range x) {
    boundary.x.start = x.start;
    boundary.x.end = x.end;
  }

  public Range getXPosition() {
    return boundary.x;
  }

  public void setYPosition(final Range y) {
    boundary.y.start = y.start;
    boundary.y.end = y.end;
  }

  public Range getYPosition() {
    return boundary.y;
  }

  // private adjustRolloverXPosition () {
  // int statusY = (ButtonHEIGHT + g.getFontMetrics().getAscent()) / 2;
  // int statusX;
  //
  // ToolButtonImage btnImage = currentRolloverBtn.getImage();
  // String status = shiftPressed ? btnImage.getDescription() : btnImage
  // .getTitle();
  //
  // if (currentRolloverBtn.isRightJustified()) { // TODO: add logic for
  // // multiple right-justified
  // // buttons
  // statusX = currentRolloverBtn.getXPosition().start - ButtonGAP -
  // g.getFontMetrics().stringWidth(status);
  // } else {
  // statusX = (allButtons.length - 1) * ButtonWIDTH + (3 * ButtonGAP);
  // }
  //
  // }
  //

  public ButtonID getId() {
    return id;
  }

  public int getToolbarPosition() {
    return toolbarPosition;
  }

  public State getState() {
    return state;
  }

  public void setState(State newState) {
    state = newState;
  }

  public Image getStateImage() {
    return image.getStateImage(state);
  }

  public boolean contains(Point clickPosition) {
    return boundary.contains(clickPosition);
  }

  public Point getStart() {
    return new Point(boundary.x.start, boundary.y.start);
  }

  public Point getEnd() {
    return new Point(boundary.x.end, boundary.y.end);
  }

  public void renderOn(Graphics g) {
    g.drawImage(getStateImage(), boundary.x.start, boundary.y.start, null);
  }

  public void renderHelpTextOn(Graphics g, boolean shiftPressed, Font helpFont, Color helpColor) {
    renderHelpText(shiftPressed? image.getDescription() : image.getTitle(), g, helpFont, helpColor);
  }
  
  private void renderHelpText(String help, Graphics g, Font helpFont,
                              Color helpColor) {
    FontMetrics fm = g.getFontMetrics();
    int xPosition = helpTextX - (isRightJustified ? fm.stringWidth(help) : 0);
    
    g.setFont(helpFont);
    g.setColor(helpColor);
    g.drawString(help, xPosition, (ButtonHEIGHT + fm.getAscent()) / 2);
  }

  // ////////////////////////////////////////////
  public static class Range {

    public int start;
    public int end;

    public Range() {
      this(0, 0);
    }

    public Range(final int start, final int end) {
      this.start = start;
      this.end = end;
    }

    public boolean contains(final int value) {
      return start <= value && value <= end;
    }
  }

  // ////////////////////////////////////////////
  public static class Boundary {

    public Range x;
    public Range y;

    public Boundary() {
      this(new Range(0, 0), new Range(0, 0));
    }

    public Boundary(final Range x, final Range y) {
      this.x = x;
      this.y = y;
    }

    public boolean contains(final Point point) {
      return x.contains(point.x) && y.contains(point.y);
    }
  }

  public void setToolbarPosition(int position) {
    this.toolbarPosition = position;
  }

  public void setHelpTextPosition(int offset) {
    helpTextX = offset;
  }
}
