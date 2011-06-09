#ifndef SIMPLEPLUGINPROGRESSWIDGET_H
#define SIMPLEPLUGINPROGRESSWIDGET_H

#include <QtGui/QWidget>

#include <tulip/SimplePluginProgress.h>

class TLP_QT_SCOPE CircleProgressBar: public QWidget {
  int _value;
  int _max;

public:
  explicit CircleProgressBar(QWidget *parent=0);
  void setValue(int value, int max);

  virtual int heightForWidth(int w) const;

protected:
  virtual void paintEvent(QPaintEvent *);
};

namespace Ui {
class SimplePluginProgressWidgetData;
}

namespace tlp {

class TLP_QT_SCOPE SimplePluginProgressWidget: public QWidget, public tlp::SimplePluginProgress {
  Q_OBJECT
  Ui::SimplePluginProgressWidgetData *_ui;

public:
  explicit SimplePluginProgressWidget(QWidget *parent=0,Qt::WindowFlags f=0);

  void setComment(std::string);
  void setComment(const QString &);
  void setComment(const char *);

protected:
  virtual void progress_handler(int step, int max_step);
  virtual void preview_handler(bool);
};

}

#endif // SIMPLEPLUGINPROGRESSWIDGET_H
