#include "ui-scrolled-canvas-skeleton.h"

static void expose(GtkWidget *widget, GdkEventExpose *event, gpointer data)
{
  //  #ifdef DEBUGMODE
    {
      printf("DEBUG: Canvas Expose\n");
    }
  //  #endif

  maincanvaspaint(widget, event, data);
}

// Expose-Event Paint Function for maincanvas //
static void maincanvaspaint(GtkWidget *widget, GdkEventExpose *event, gpointer data)
{
  printf("zoom is: %lf\n", zoom_level);
  maincanvas_drawable = maincanvas->window; // drawable drawing area window //
  //maincanvas_drawable = GTK_LAYOUT(maincanvas)->bin_window; // drawable layout window //
  maincanvas_cs = gdk_cairo_create(maincanvas_drawable); // corresponding cairo state //

  // call main drawing function //
  /*We have made two rectangles just that, should add more, not thatimportant now*/
  // Set line width
  cairo_set_line_width(maincanvas_cs, 2);

  // Rectangle coordinates: x, y, width, height
  /*Draw the window black*/
  cairo_set_source_rgb(maincanvas_cs, 0.0, 0.0, 0.0); // Black color
  cairo_rectangle(maincanvas_cs, 0, 0, maincanvasWidth, maincanvasHeight);
  cairo_fill(maincanvas_cs);

  /*Create a white frame around the black window*/
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, 0, 0, maincanvasWidth, maincanvasHeight);
  cairo_stroke(maincanvas_cs); // Draw outline only

  //Apply cliping
  cairo_reset_clip(maincanvas_cs);
  cairo_rectangle(maincanvas_cs, 0, 0, maincanvasWidth, maincanvasHeight);
  cairo_clip(maincanvas_cs);

  // Draw rectangles

  // Red rectangle
  double redRectX = (135 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double redRectY = (330 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double redRectWidth = (50 * maincanvasWidth / 700) * zoom_level;
  double redRectHeight = (20 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 1.0, 0.0, 0.0); // Red color
  cairo_rectangle(maincanvas_cs, redRectX, redRectY, redRectWidth, redRectHeight);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, redRectX, redRectY, redRectWidth, redRectHeight);
  cairo_stroke(maincanvas_cs);

  // Green rectangle
  double greenRectX = (120 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double greenRectY = (350 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double greenRectWidth = (20 * maincanvasWidth / 700) * zoom_level;
  double greenRectHeight = (45 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 0.0, 1.0, 0.0); // Green color
  cairo_rectangle(maincanvas_cs, greenRectX, greenRectY, greenRectWidth, greenRectHeight);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, greenRectX, greenRectY, greenRectWidth, greenRectHeight);
  cairo_stroke(maincanvas_cs);

  // Draw interconnects
  cairo_set_line_width(maincanvas_cs, 2);
  cairo_set_source_rgb(maincanvas_cs, 0.0, 1.0, 1.0); // Purple color

  // Interconnect between red and green rectangles
  cairo_move_to(maincanvas_cs, redRectX + redRectWidth, redRectY + redRectHeight / 2);
  cairo_line_to(maincanvas_cs, greenRectX, greenRectY + greenRectHeight / 2);
  cairo_stroke(maincanvas_cs);

  // Blue rectangle
  double blueRectX = (180 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double blueRectY = (350 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double blueRectWidth = (20 * maincanvasWidth / 700) * zoom_level;
  double blueRectHeight = (45 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 0.0, 0.0, 1.0); // Blue color
  cairo_rectangle(maincanvas_cs, blueRectX, blueRectY, blueRectWidth, blueRectHeight);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, blueRectX, blueRectY, blueRectWidth, blueRectHeight);
  cairo_stroke(maincanvas_cs);

  // Light blue rectangle
  double lightBlueRectX = (120 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double lightBlueRectY = (395 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double lightBlueRectWidth = (80 * maincanvasWidth / 700) * zoom_level;
  double lightBlueRectHeight = (20 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 0.0, 1.0, 1.0); // Light blue color
  cairo_rectangle(maincanvas_cs, lightBlueRectX, lightBlueRectY, lightBlueRectWidth, lightBlueRectHeight);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, lightBlueRectX, lightBlueRectY, lightBlueRectWidth, lightBlueRectHeight);
  cairo_stroke(maincanvas_cs);

  // Draw interconnects
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 0.0); // Black color

  // Interconnect between green and light blue rectangles
  cairo_move_to(maincanvas_cs, greenRectX + greenRectWidth, greenRectY + greenRectHeight / 2);
  cairo_line_to(maincanvas_cs, lightBlueRectX, lightBlueRectY + lightBlueRectHeight / 2);
  cairo_stroke(maincanvas_cs);

  // Magenta rectangle
  double magentaRectX = (120 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double magentaRectY = (415 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double magentaRectWidth = (20 * maincanvasWidth / 700) * zoom_level;
  double magentaRectHeight = (65 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 1.0, 0.0, 1.0); // Magenta color
  cairo_rectangle(maincanvas_cs, magentaRectX, magentaRectY, magentaRectWidth, magentaRectHeight);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, magentaRectX, magentaRectY, magentaRectWidth, magentaRectHeight);
  cairo_stroke(maincanvas_cs);

  // Magenta rectangle 2
  double magentaRect2X = (180 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double magentaRect2Y = (415 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double magentaRect2Width = (20 * maincanvasWidth / 700) * zoom_level;
  double magentaRect2Height = (65 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 1.0, 0.0, 1.0); // Magenta color
  cairo_rectangle(maincanvas_cs, magentaRect2X, magentaRect2Y, magentaRect2Width, magentaRect2Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, magentaRect2X, magentaRect2Y, magentaRect2Width, magentaRect2Height);
  cairo_stroke(maincanvas_cs);

  // Red rectangle 2
  double redRect2X = (300 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double redRect2Y = (330 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double redRect2Width = (50 * maincanvasWidth / 700) * zoom_level;
  double redRect2Height = (20 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 1.0, 0.0, 0.0); // Red color
  cairo_rectangle(maincanvas_cs, redRect2X, redRect2Y, redRect2Width, redRect2Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, redRect2X, redRect2Y, redRect2Width, redRect2Height);
  cairo_stroke(maincanvas_cs);

  // Red rectangle 3
  double redRect3X = (280 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double redRect3Y = (350 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double redRect3Width = (20 * maincanvasWidth / 700) * zoom_level;
  double redRect3Height = (50 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 1.0, 0.0, 0.0); // Red color
  cairo_rectangle(maincanvas_cs, redRect3X, redRect3Y, redRect3Width, redRect3Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, redRect3X, redRect3Y, redRect3Width, redRect3Height);
  cairo_stroke(maincanvas_cs);

  // Light blue rectangle 2
  double lightBlueRect2X = (300 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double lightBlueRect2Y = (400 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double lightBlueRect2Width = (50 * maincanvasWidth / 700) * zoom_level;
  double lightBlueRect2Height = (20 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 0.0, 1.0, 1.0); // Light blue color
  cairo_rectangle(maincanvas_cs, lightBlueRect2X, lightBlueRect2Y, lightBlueRect2Width, lightBlueRect2Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, lightBlueRect2X, lightBlueRect2Y, lightBlueRect2Width, lightBlueRect2Height);
  cairo_stroke(maincanvas_cs);

  // Blue rectangle 2
  double blueRect2X = (350 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double blueRect2Y = (420 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double blueRect2Width = (20 * maincanvasWidth / 700) * zoom_level;
  double blueRect2Height = (50 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 0.0, 0.0, 1.0); // Blue color
  cairo_rectangle(maincanvas_cs, blueRect2X, blueRect2Y, blueRect2Width, blueRect2Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, blueRect2X, blueRect2Y, blueRect2Width, blueRect2Height);
  cairo_stroke(maincanvas_cs);

  // Green rectangle 2
  double greenRect2X = (300 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double greenRect2Y = (470 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double greenRect2Width = (50 * maincanvasWidth / 700) * zoom_level;
  double greenRect2Height = (20 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 0.0, 0.5, 0.0); // Deep green color
  cairo_rectangle(maincanvas_cs, greenRect2X, greenRect2Y, greenRect2Width, greenRect2Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, greenRect2X, greenRect2Y, greenRect2Width, greenRect2Height);
  cairo_stroke(maincanvas_cs);


  // Green rectangle 3
  double greenRect3X = (460 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double greenRect3Y = (340 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double greenRect3Width = (20 * maincanvasWidth / 700) * zoom_level;
  double greenRect3Height = (140 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 0.0, 0.5, 0.0); // Deep green color
  cairo_rectangle(maincanvas_cs, greenRect3X, greenRect3Y, greenRect3Width, greenRect3Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, greenRect3X, greenRect3Y, greenRect3Width, greenRect3Height);
  cairo_stroke(maincanvas_cs);

  // Orange rectangle 2
  double orangeRect2X = (480 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double orangeRect2Y = (320 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double orangeRect2Width = (60 * maincanvasWidth / 700) * zoom_level;
  double orangeRect2Height = (20 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 1.0, 0.5, 0.0); // Orange color
  cairo_rectangle(maincanvas_cs, orangeRect2X, orangeRect2Y, orangeRect2Width, orangeRect2Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, orangeRect2X, orangeRect2Y, orangeRect2Width, orangeRect2Height);
  cairo_stroke(maincanvas_cs);

  // Yellow rectangle 2
  double yellowRect2X = (480 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double yellowRect2Y = (395 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double yellowRect2Width = (60 * maincanvasWidth / 700) * zoom_level;
  double yellowRect2Height = (20 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 0.0); // Yellow color
  cairo_rectangle(maincanvas_cs, yellowRect2X, yellowRect2Y, yellowRect2Width, yellowRect2Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, yellowRect2X, yellowRect2Y, yellowRect2Width, yellowRect2Height);
  cairo_stroke(maincanvas_cs);

  // Deep purple rectangle 2
  double purpleRect2X = (540 * maincanvasWidth / 700) * zoom_level - maincanvasOx;
  double purpleRect2Y = (340 * maincanvasHeight / 700) * zoom_level - maincanvasOy;
  double purpleRect2Width = (20 * maincanvasWidth / 700) * zoom_level;
  double purpleRect2Height = (60 * maincanvasHeight / 700) * zoom_level;

  cairo_set_source_rgb(maincanvas_cs, 0.5, 0.0, 0.5); // Deep purple color
  cairo_rectangle(maincanvas_cs, purpleRect2X, purpleRect2Y, purpleRect2Width, purpleRect2Height);
  cairo_fill(maincanvas_cs);
  cairo_set_source_rgb(maincanvas_cs, 1.0, 1.0, 1.0); // White color
  cairo_rectangle(maincanvas_cs, purpleRect2X, purpleRect2Y, purpleRect2Width, purpleRect2Height);
  cairo_stroke(maincanvas_cs);

  cairo_reset_clip(maincanvas_cs);
  cairo_rectangle(maincanvas_cs, zoom_level*(0-maincanvasOx), zoom_level*(0-maincanvasOy), zoom_level*maincanvasWidth, zoom_level*maincanvasHeight);
  cairo_clip(maincanvas_cs);

  // Draw a rectangle that extends beyond the clipped region
  cairo_set_source_rgb(maincanvas_cs, 0.5, 0.6, 0.7); //Greyish color
  cairo_rectangle(maincanvas_cs, (maincanvasWidth)*zoom_level-maincanvasOx, (maincanvasHeight)*zoom_level-maincanvasOy, 100*zoom_level, 100*zoom_level); // Rectangle extends beyond the canvas size
  cairo_fill(maincanvas_cs);

  cairo_destroy(maincanvas_cs);
}

// Size-Allocate Event Function for maincanvas // 
static void resizemaincanvas(GtkWidget *widget, GdkRectangle *gdkrect, gpointer data)
{
  int newmaincanvasWidth = gdkrect->width;
  int newmaincanvasHeight = gdkrect->height;
  
  //  #ifdef DEBUGMODE
    {
      printf("DEBUG: Resize Main Canvas.\n");
      printf("DEBUG: Current Width, Height = (%d, %d), New Width, Height = (%d, %d)\n", maincanvasWidth, maincanvasHeight, gdkrect->width, gdkrect->height);
    }
  //  #endif

  // resize code //
  maincanvasWidth = newmaincanvasWidth;
  maincanvasHeight = newmaincanvasHeight;

  // Redraw the display when the window is resized
  gtk_widget_queue_draw(widget);
}

static gboolean maincanvasvscroll(GtkRange *range, GtkScrollType scroll, gdouble value, gpointer data)
{
  // Get the adjustment of the horizontal scrollbar
  //GtkAdjustment *adjustment = gtk_range_get_adjustment(range);

  adjust_scrollbar = gtk_range_get_adjustment(range);
    
  // Get the current values of the adjustment
  double lower = gtk_adjustment_get_lower(adjust_scrollbar);
  double upper = gtk_adjustment_get_upper(adjust_scrollbar);
  double page_size = gtk_adjustment_get_page_size(adjust_scrollbar);

  gtk_adjustment_set_lower(adjust_scrollbar, lower = -maincanvasHeight);
  gtk_adjustment_set_upper(adjust_scrollbar, upper = maincanvasHeight);
  //gtk_adjustment_set_page_size(adjust_scrollbar, page_size = 550.0);

  // Calculate the maximum x-offset value
  double maxmaincanvasOy = upper;

  // Calculate the calibrated x-offset value based on the scrollbar's value
  int ivalue = (int)((value));

  maincanvasOy = ivalue;
  //  #ifdef DEBUGMODE
    {
      printf("DEBUG: Vertical Scroll\n");
      printf("DEBUG: Scroll value = %.3f\n", value);
    }
  //  #endif 

  // Update the x-offset based on the scroll direction
/*  switch (scroll)
  {
    // Scroll down
    case GTK_SCROLL_STEP_BACKWARD:
      maincanvasOy = ivalue;
      printf("Scroll down\n");
      break;

    // Scroll up
    case GTK_SCROLL_STEP_FORWARD:
      maincanvasOy = ivalue;
      printf("Scroll up\n");
      break;

    default:
      break;
  }
*/
  // Perform bounds checking to prevent maincanvasOx from going out of bounds
  if (maincanvasOy < -maincanvasHeight)
  {
    maincanvasOy = lower; // Limit minimum value
  }
  else if (maincanvasOy > maxmaincanvasOy)
  {
    maincanvasOy = maxmaincanvasOy; // Limit maximum value
  }

  // Configure the adjustment with the updated x-offset
  //gtk_adjustment_set_value(adjustment, maincanvasOy);

  // Update the canvas display
  gtk_widget_queue_draw(maincanvas);
  
}

static gboolean maincanvashscroll(GtkRange *range, GtkScrollType scroll, gdouble value, gpointer data)
{
  // Get the adjustment of the horizontal scrollbar
  adjust_scrollbar = gtk_range_get_adjustment(range);
    
  // Get the current values of the adjustment
  double lower = gtk_adjustment_get_lower(adjust_scrollbar);
  double upper = gtk_adjustment_get_upper(adjust_scrollbar);
  double page_size = gtk_adjustment_get_page_size(adjust_scrollbar);

  gtk_adjustment_set_lower(adjust_scrollbar, lower = -maincanvasHeight);
  gtk_adjustment_set_upper(adjust_scrollbar, upper = maincanvasHeight);
  //gtk_adjustment_set_page_size(adjust_scrollbar, page_size = 550.0);

  // Calculate the maximum x-offset value
  double maxmaincanvasOx = upper;

  // Calculate the calibrated x-offset value based on the scrollbar's value
  int ivalue = (int)(value);

  maincanvasOx = ivalue;
  // Update the x-offset based on the scroll direction
  /*switch (scroll)
  {
    // Scroll to the left
    case GTK_SCROLL_STEP_BACKWARD:
      maincanvasOx -= ivalue;
      printf("Scroll to the left\n");
      break;

    // Scroll to the right
    case GTK_SCROLL_STEP_FORWARD:
      maincanvasOx += ivalue;
      printf("Scroll to the right\n");
      break;

    default:
      break;
  }*/

  // Perform bounds checking to prevent maincanvasOx from going out of bounds
  if (maincanvasOx < -maincanvasWidth)
  {
    maincanvasOx = lower; // Limit minimum value
  }
  else if (maincanvasOx > maxmaincanvasOx)
  {
    maincanvasOx = maxmaincanvasOx; // Limit maximum value
  }

  // Update the canvas display
  gtk_widget_queue_draw(maincanvas);
}

//Seems ok let's get it
static void scroll(GtkWidget *widget, GdkEventScroll *eev, gpointer data)
{
  //zoom factor helps us zoom-in or zoom-out times or divisions based on this number
  double zoom_factor = 1.05;

  //  #ifdef DEBUGMODE
    {
      printf("DEBUG: Canvas Mouse Scroll\n");
    }
  //  #endif

  // mouse wheel (scroll) code here //
  if(eev->direction == GDK_SCROLL_UP)
  {
    (zoom_level) = (zoom_level)*zoom_factor;
    printf("zoom-in: %lf\n", zoom_level);
    gtk_widget_queue_draw(widget);
  }
  else if(eev->direction == GDK_SCROLL_DOWN)
  {
    (zoom_level) = (zoom_level)/zoom_factor;
    printf("zoom-out: %lf\n", zoom_level);
    gtk_widget_queue_draw(widget);
  }
}

void setupscrolladjustments()
{
  // setup horizontal and vertical scrollbar adjustments //
  //Horizontal
  scaledhpagesize = (zoom_level * ((double) maincanvasWidth));
  hpagesize = ((double) maincanvasWidth);
  hstep = 0.05 * hpagesize;

  //Vertical
  scaledvpagesize = (zoom_level * ((double) maincanvasHeight));
  vpagesize = ((double) maincanvasHeight);
  vstep = 0.05 * vpagesize;

  // use gtk_adjustment_configure() //
  gtk_adjustment_configure(maincanvashscrollbaradjustment, maincanvasOx,/*lower:*/ 0.0,/*upper:*/ scaledhpagesize, /*step_increament:*/hstep, /*page_increament:*/hstep, /*page_size:*/hpagesize);
  gtk_adjustment_configure(maincanvasvscrollbaradjustment, maincanvasOy,/*lower:*/ 0.0,/*upper:*/ scaledvpagesize, /*step_increament:*/vstep, /*page_increament:*/vstep, /*page_size:*/vpagesize);
}

static void mousebutton(GtkWidget *widget, GdkEventButton *eev, gpointer data)
{
  //  #ifdef DEBUGMODE
    {
      printf("DEBUG: Mouse Button %d Pressed\n", eev->button);
    }
  //  #endif

  if (eev->button == 1) // Left Mouse Button //
    {
      // code here //
      zoom_level = 1.0;
      maincanvasOx = 0;
      maincanvasOy = 0;
      printf("zoom back to the original level: %lf\n", zoom_level);
      gtk_widget_queue_draw(widget);
    }

  if (eev->button == 3) // Right Mouse Button //
    {
      // code here //
    }
  
}

static void quitaction()
{
  #ifdef DEBUGMODE
    {
      printf("DEBUG: Quit Action\n");
    }
  #endif
  
  printf("Thank you. Bye now.\n");
  gtk_main_quit();
}


void start_gui()
{  
  // *** Local Variables *** //

  GtkWidget *maincanvashbox; // contains maincanvas and vertical scrollbar //
  GtkWidget *maincanvasvbox; // contains maincanvashbox and horizontal scrollbar //

  GtkWidget *hpane; // horizontal pane //
  GtkWidget *hpane2; // horizontal pane //

  GtkWidget *mainframe; // main canvas frame //
  GtkWidget *hierarchybrowserframe; // hierarchy browser frame //

  // *** Local Variables End *** //

  gtk_init(NULL,  NULL);

  mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  gtk_window_set_title(GTK_WINDOW(mainwindow), "CADII - Assignment 2");
  gtk_window_set_default_size(GTK_WINDOW(mainwindow), 300, 300); // default size //
  
  g_signal_connect(G_OBJECT(mainwindow), "destroy", G_CALLBACK(quitaction), mainwindow);

  maincanvashbox = gtk_hbox_new(FALSE, 0);
  maincanvasvbox = gtk_vbox_new(FALSE, 0);

  // Frames //
  mainframe = gtk_frame_new("Layout View");
  hierarchybrowserframe = gtk_frame_new("Other Frame");

  // Canvas Drawing Area, Frames and Associated Callbacks //
  maincanvas = gtk_drawing_area_new();
  //  maincanvas = gtk_layout_new(NULL, NULL);

  gtk_widget_set_size_request(maincanvas, maincanvasWidth, maincanvasHeight);

  // Application Paintable and Double-Buffering Flags for maincanvas //
  //  gtk_widget_set_app_paintable(maincanvas, FALSE);
  //  gtk_widget_set_double_buffered(maincanvas, FALSE);

  // maincanvas Event Handlers //
  g_signal_connect(G_OBJECT(maincanvas), "expose-event", G_CALLBACK(expose), maincanvas);

  gtk_widget_add_events(maincanvas, GDK_SCROLL);
  gtk_widget_add_events(maincanvas, GDK_BUTTON_PRESS_MASK);

  g_signal_connect(G_OBJECT(maincanvas), "scroll-event", G_CALLBACK(scroll), maincanvas);
  g_signal_connect(G_OBJECT(maincanvas), "button-press-event", G_CALLBACK(mousebutton), maincanvas);
  
  maincanvasvscrollbaradjustment = gtk_adjustment_new(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  maincanvashscrollbaradjustment = gtk_adjustment_new(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

  // setup horizontal and vertical scrollbar adjustments //
  setupscrolladjustments();

  maincanvasvscrollbar = gtk_vscrollbar_new(GTK_ADJUSTMENT(maincanvasvscrollbaradjustment));
  maincanvashscrollbar = gtk_hscrollbar_new(GTK_ADJUSTMENT(maincanvashscrollbaradjustment));

  g_signal_connect(G_OBJECT(maincanvasvscrollbar), "change-value", G_CALLBACK(maincanvasvscroll), maincanvasvscrollbar);
  g_signal_connect(G_OBJECT(maincanvashscrollbar), "change-value", G_CALLBACK(maincanvashscroll), maincanvashscrollbar);

  // Two Boxes and one Pane Layout //

  gtk_box_pack_start(GTK_BOX(maincanvashbox), maincanvas, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(maincanvashbox), maincanvasvscrollbar, FALSE, FALSE, 0);

  gtk_box_set_child_packing(GTK_BOX(maincanvashbox), maincanvas, TRUE, TRUE, 0, GTK_PACK_START);
  gtk_box_set_child_packing(GTK_BOX(maincanvashbox), maincanvasvscrollbar, FALSE, FALSE, 0, GTK_PACK_END);

  gtk_box_pack_start(GTK_BOX(maincanvasvbox), maincanvashbox, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(maincanvasvbox), maincanvashscrollbar, FALSE, FALSE, 0);

  gtk_box_set_child_packing(GTK_BOX(maincanvasvbox), maincanvashbox, TRUE, TRUE, 0, GTK_PACK_START);
  gtk_box_set_child_packing(GTK_BOX(maincanvasvbox), maincanvashscrollbar, FALSE, FALSE, 0, GTK_PACK_END);

  gtk_container_add(GTK_CONTAINER(mainframe), maincanvasvbox);

  g_signal_connect(G_OBJECT(maincanvas), "size-allocate", G_CALLBACK(resizemaincanvas), maincanvas);

  hpane = gtk_hpaned_new();
  gtk_paned_add1(GTK_PANED(hpane), hierarchybrowserframe);
  gtk_paned_add2(GTK_PANED(hpane), mainframe);  

  gtk_container_add(GTK_CONTAINER(mainwindow), hpane);

  gtk_widget_show_all(mainwindow);

  gtk_main();

}

gint main (gint argc, gchar **argv)
{
  // you may call start_gui() from TCL, based on a TCL command //
  // alternatively, you may create a thread, but this is a lot more complex! //
  start_gui();

  return EXIT_SUCCESS;

}