#!/bin/sh

# This script adds a menu item, icons and mime type for Arduino for the current
# user. If possible, it will use the xdg-utils - or fall back to just creating
# and copying a desktop file to the user's dir.
# If called with the "-u" option, it will undo the changes.

# Resource name to use (including vendor prefix)
RESOURCE_NAME=arduino-arduinoide

# Get absolute path from which this script file was executed
# (Could be changed to "pwd -P" to resolve symlinks to their target)
SCRIPT_PATH=$( cd $(dirname $0) ; pwd )
cd "$SCRIPT_PATH"

# Default mode is to install.
UNINSTALL=false

# Install using xdg-utils
xdg_install_f() {

  # Create a temp dir accessible by all users
  TMP_DIR=`mktemp --directory`

  # Create *.desktop file using the existing template file
  sed -e "s,<BINARY_LOCATION>,${SCRIPT_PATH}/arduino,g" \
      -e "s,<ICON_NAME>,${RESOURCE_NAME},g" "${SCRIPT_PATH}/lib/desktop.template" > "${TMP_DIR}/${RESOURCE_NAME}.desktop"

  # Install the icon files using name and resolutions
  xdg-icon-resource install --context apps --size 16 "${SCRIPT_PATH}/lib/icons/16x16/apps/arduino.png" $RESOURCE_NAME
  xdg-icon-resource install --context apps --size 24 "${SCRIPT_PATH}/lib/icons/24x24/apps/arduino.png" $RESOURCE_NAME
  xdg-icon-resource install --context apps --size 32 "${SCRIPT_PATH}/lib/icons/32x32/apps/arduino.png" $RESOURCE_NAME
  xdg-icon-resource install --context apps --size 48 "${SCRIPT_PATH}/lib/icons/48x48/apps/arduino.png" $RESOURCE_NAME
  xdg-icon-resource install --context apps --size 64 "${SCRIPT_PATH}/lib/icons/64x64/apps/arduino.png" $RESOURCE_NAME
  xdg-icon-resource install --context apps --size 72 "${SCRIPT_PATH}/lib/icons/72x72/apps/arduino.png" $RESOURCE_NAME
  xdg-icon-resource install --context apps --size 96 "${SCRIPT_PATH}/lib/icons/96x96/apps/arduino.png" $RESOURCE_NAME
  xdg-icon-resource install --context apps --size 128 "${SCRIPT_PATH}/lib/icons/128x128/apps/arduino.png" $RESOURCE_NAME
  xdg-icon-resource install --context apps --size 256 "${SCRIPT_PATH}/lib/icons/256x256/apps/arduino.png" $RESOURCE_NAME

  # Install the created *.desktop file
  xdg-desktop-menu install "${TMP_DIR}/${RESOURCE_NAME}.desktop"

  # Create icon on the desktop
  xdg-desktop-icon install "${TMP_DIR}/${RESOURCE_NAME}.desktop"

  # Install Arduino mime type
  xdg-mime install "${SCRIPT_PATH}/lib/${RESOURCE_NAME}.xml"

  # Install icons for mime type
  xdg-icon-resource install --context mimetypes --size 16 "${SCRIPT_PATH}/lib/icons/16x16/apps/arduino.png" text-x-arduino
  xdg-icon-resource install --context mimetypes --size 24 "${SCRIPT_PATH}/lib/icons/24x24/apps/arduino.png" text-x-arduino
  xdg-icon-resource install --context mimetypes --size 32 "${SCRIPT_PATH}/lib/icons/32x32/apps/arduino.png" text-x-arduino
  xdg-icon-resource install --context mimetypes --size 48 "${SCRIPT_PATH}/lib/icons/48x48/apps/arduino.png" text-x-arduino
  xdg-icon-resource install --context mimetypes --size 64 "${SCRIPT_PATH}/lib/icons/64x64/apps/arduino.png" text-x-arduino
  xdg-icon-resource install --context mimetypes --size 72 "${SCRIPT_PATH}/lib/icons/72x72/apps/arduino.png" text-x-arduino
  xdg-icon-resource install --context mimetypes --size 96 "${SCRIPT_PATH}/lib/icons/96x96/apps/arduino.png" text-x-arduino
  xdg-icon-resource install --context mimetypes --size 128 "${SCRIPT_PATH}/lib/icons/128x128/apps/arduino.png" text-x-arduino
  xdg-icon-resource install --context mimetypes --size 256 "${SCRIPT_PATH}/lib/icons/256x256/apps/arduino.png" text-x-arduino

  # Make Arduino IDE the default application for *.ino
  xdg-mime default ${RESOURCE_NAME}.desktop text/x-arduino

  # Clean up
  rm "${TMP_DIR}/${RESOURCE_NAME}.desktop"
  rmdir "$TMP_DIR"

}

# Install by simply copying desktop file (fallback)
simple_install_f() {

  # Create a temp dir accessible by all users
  TMP_DIR=`mktemp --directory`

  # Create *.desktop file using the existing template file
  sed -e "s,<BINARY_LOCATION>,${SCRIPT_PATH}/arduino,g" \
      -e "s,<ICON_NAME>,${SCRIPT_PATH}/lib/arduino.png,g" "${SCRIPT_PATH}/lib/desktop.template" > "${TMP_DIR}/${RESOURCE_NAME}.desktop"

  mkdir -p ~/.local/share/applications
  cp "${TMP_DIR}/${RESOURCE_NAME}.desktop" ~/.local/share/applications/

  # Create desktop icon if dir exists
  if [ -d ~/Desktop ]; then
   cp "${TMP_DIR}/${RESOURCE_NAME}.desktop" ~/Desktop/
  fi

  # Clean up
  rm "${TMP_DIR}/${RESOURCE_NAME}.desktop"
  rmdir "$TMP_DIR"

}

# Uninstall using xdg-utils
xdg_uninstall_f() {

  # Remove *.desktop file
  xdg-desktop-menu uninstall ${RESOURCE_NAME}.desktop

  # Remove icon from desktop
  xdg-desktop-icon uninstall ${RESOURCE_NAME}.desktop

  # Remove icons
  xdg-icon-resource uninstall --size 16 $RESOURCE_NAME
  xdg-icon-resource uninstall --size 24 $RESOURCE_NAME
  xdg-icon-resource uninstall --size 32 $RESOURCE_NAME
  xdg-icon-resource uninstall --size 48 $RESOURCE_NAME
  xdg-icon-resource uninstall --size 64 $RESOURCE_NAME
  xdg-icon-resource uninstall --size 72 $RESOURCE_NAME
  xdg-icon-resource uninstall --size 96 $RESOURCE_NAME
  xdg-icon-resource uninstall --size 128 $RESOURCE_NAME
  xdg-icon-resource uninstall --size 256 $RESOURCE_NAME

  # Remove MIME type icons
  xdg-icon-resource uninstall --size 16  text-x-arduino
  xdg-icon-resource uninstall --size 24  text-x-arduino
  xdg-icon-resource uninstall --size 32  text-x-arduino
  xdg-icon-resource uninstall --size 48  text-x-arduino
  xdg-icon-resource uninstall --size 64  text-x-arduino
  xdg-icon-resource uninstall --size 72  text-x-arduino
  xdg-icon-resource uninstall --size 96  text-x-arduino
  xdg-icon-resource uninstall --size 128  text-x-arduino
  xdg-icon-resource uninstall --size 256  text-x-arduino

  # Remove Arduino MIME type
  xdg-mime uninstall "${SCRIPT_PATH}/lib/${RESOURCE_NAME}.xml"

}

# Uninstall by simply removing desktop files (fallback), incl. old one
simple_uninstall_f() {

  if [ -f ~/.local/share/applications/arduino.desktop ]; then
    rm ~/.local/share/applications/arduino.desktop
  fi

  if [ -f ~/.local/share/applications/${RESOURCE_NAME}.desktop ]; then
    rm ~/.local/share/applications/${RESOURCE_NAME}.desktop
  fi

  if [ -f ~/Desktop/arduino.desktop ]; then
    rm ~/Desktop/arduino.desktop
  fi

  if [ -f ~/Desktop/${RESOURCE_NAME}.desktop ]; then
    rm ~/Desktop/${RESOURCE_NAME}.desktop
  fi

}

# Update desktop file and mime databases (if possible)
updatedbs_f() {

  if [ -d ~/.local/share/applications ]; then
    if command -v update-desktop-database > /dev/null; then
      update-desktop-database ~/.local/share/applications
    fi
  fi

  if [ -d ~/.local/share/mime ]; then
    if command -v update-mime-database > /dev/null; then
      update-mime-database ~/.local/share/mime
    fi
  fi

}

# Check availability of xdg-utils
xdg_exists_f() {

  if ! command -v xdg-icon-resource > /dev/null; then return 1; fi
  if ! command -v xdg-desktop-menu > /dev/null; then return 1; fi
  if ! command -v xdg-desktop-icon > /dev/null; then return 1; fi
  if ! command -v xdg-mime > /dev/null; then return 1; fi
  return 0

}

# Shows a description of the available options
display_help_f() {
  echo "\n"
  echo "This script will add a Arduino IDE desktop shortcut, menu item,"
  echo "icons and file associations for the current user."
  if ! xdg_exists_f; then
    echo "\n"
    echo "xdg-utils are recommended to be installed, so this script can use them."
  fi
  echo "\n"
  echo "Optional arguments are:"
  echo "\n"
  echo "\t-u, --uninstall\t\tRemoves shortcut, menu item and icons."
  echo "\n"
  echo "\t-h, --help\t\tShows this help again."
  echo "\n"
}

# Check for provided arguments
while [ $# -gt 0 ] ; do
  ARG="$1"
  case $ARG in
      -u|--uninstall)
        UNINSTALL=true
        shift
      ;;
      -h|--help)
        display_help_f
        exit 0
      ;;
      *)
        echo "\n"
        echo "Invalid option -- '$ARG'"
        display_help_f
        exit 1
      ;;
  esac
done

# If possible, use xdg-utils, if not, use a more basic approach
if xdg_exists_f; then
  if [ "$UNINSTALL" = true ]; then
    echo "Removing desktop shortcut and menu item for Arduino IDE..."
    xdg_uninstall_f
    simple_uninstall_f
  else
    echo "Adding desktop shortcut, menu item and file associations for Arduino IDE..."
    xdg_uninstall_f
    simple_uninstall_f
    xdg_install_f
  fi
else
  if [ "$UNINSTALL" = true ]; then
    echo "Removing desktop shortcut and menu item for Arduino IDE..."
    simple_uninstall_f
  else
    echo "Adding desktop shortcut and menu item for Arduino IDE..."
    simple_uninstall_f
    simple_install_f
  fi
fi
updatedbs_f
echo "...done!"

exit 0
