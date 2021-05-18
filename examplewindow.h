#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include <gtkmm/window.h> // Gtk::Window
#include <gtkmm/frame.h> // Gtk::Frame
#include <gtkmm/paned.h>
class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  //Signal handlers:
  bool on_timeout();
  void on_button_close();
  void on_button_Calculate();
  //Child widgets:
  Gtk::Box m_Box;
  Gtk::Box Box1_;
  Gtk::Box Box2_;
  Gtk::Label label_a_,label_b_,label_c_,label_d_,label_e_,label_f_,label_g_;
  Gtk::Entry a;
  Gtk::Entry b;
  Gtk::Entry c;
  Gtk::Entry d;
  Gtk::Entry e;
  Gtk::Entry f;
  Gtk::Entry g;
  Gtk::Separator m_Separator;
  Gtk::Button Calculate_button;
  Gtk::Button m_Button_Close;
};

#endif //GTKMM_EXAMPLEWINDOW_H