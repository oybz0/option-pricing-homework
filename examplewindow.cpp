#include "examplewindow.h"
#include <iostream>
#include <string>
#include "calculate.cpp"
ExampleWindow::ExampleWindow()
: m_Box(Gtk::Orientation::VERTICAL),
  Box1_(Gtk::Orientation::VERTICAL),
  Box2_(Gtk::Orientation::VERTICAL),
  m_Button_Close("Close"),
  label_a_{"F: "},
  label_b_{"K: "},
  label_c_{"r: "},
  label_d_{"sigma: "},
  label_e_{"time: "},
  label_f_{"price: "}{

  set_default_size( 1000, 500 );
  set_title("Gtk::Entry");
  set_child(m_Box);
  a.set_max_length(15);
  a.set_size_request(80, 20);

  b.set_size_request(80, 20);
  b.set_max_length(15);

  c.set_size_request(80, 20);
  c.set_max_length(15);

  d.set_size_request(80, 20);
  d.set_max_length(15);

  e.set_size_request(80, 20);
  e.set_max_length(15);

  f.set_size_request(80, 20);
  f.set_max_length(15);


  Box1_.set_margin(10);
  Box2_.set_margin(10);
  Box1_.append(*Gtk::make_managed<Gtk::Label>("F:", 0));
  Box1_.append(a); 
  Box1_.append(*Gtk::make_managed<Gtk::Label>("K:", 0));
  Box1_.append(b); 
  Box1_.append(*Gtk::make_managed<Gtk::Label>("r:", 0));
  Box1_.append(c);
  Box1_.append(*Gtk::make_managed<Gtk::Label>("sigma:", 0));
  Box1_.append(d);
  Box1_.append(*Gtk::make_managed<Gtk::Label>("time:", 0));
  Box1_.append(e);
  Box1_.append(*Gtk::make_managed<Gtk::Label>("price:", 0));
  Box1_.append(f);
  
  // add(mFixedContainer);
  // mFixedContainer.add(a);
  // mFixedContainer.add(b);
  // mFixedContainer.add(c);
  // mFixedContainer.add(mListView);


  //Change the progress fraction every 0.1 second:
  // Glib::signal_timeout().connect(
  //   sigc::mem_fun(*this, &ExampleWindow::on_timeout),
  //   100
  // );
  //cout << a <<"\n";
  Calculate_button.signal_clicked().connect(sigc::mem_fun(*this,&ExampleWindow::on_button_Calculate) );
  //float price = ExampleWindow::on_button_Calculate;
  m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
              &ExampleWindow::on_button_close) );
  Calculate_button.set_label("Calculate");
  Calculate_button.set_size_request(120,20);

  Box2_.append(Calculate_button);
  Box2_.append(m_Button_Close);

  m_Box.append(Box1_);
  m_Box.append(m_Separator);
  m_Box.append(Box2_);
  show();
}

ExampleWindow::~ExampleWindow()
{
  

}

// bool ExampleWindow::on_timeout()
// {
//   static double fraction = 0;
//   m_Entry.set_progress_fraction(fraction);

//   fraction += 0.01;
//   if(fraction > 1)
//     fraction = 0;

//   return true;
// }
void ExampleWindow::on_button_Calculate()
{
  double F = stod(a.get_text());
  double K = stod(b.get_text()); 
  double r = stod(c.get_text());
  double sigma = stod(d.get_text());
  double time = stod(e.get_text());
  double price = futures_option_price_call_european_black(F,
    K,r,sigma,time);
  f.set_text(to_string(price));
}

void ExampleWindow::on_button_close()
{
  hide();
}
