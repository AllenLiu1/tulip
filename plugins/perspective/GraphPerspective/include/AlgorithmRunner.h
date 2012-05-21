/**
 *
 * This file is part of Tulip (www.tulip-software.org)
 *
 * Authors: David Auber and the Tulip development Team
 * from LaBRI, University of Bordeaux 1 and Inria Bordeaux - Sud Ouest
 *
 * Tulip is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * Tulip is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 */
#ifndef ALGORITHMRUNNER_H
#define ALGORITHMRUNNER_H

#include <QtGui/QWidget>
#include <tulip/DataSet.h>

class QToolButton;
namespace Ui {
class AlgorithmRunner;
class AlgorithmRunnerItem;
}
namespace tlp {
class Graph;
}

class AlgorithmRunner: public QWidget {
  Q_OBJECT

  Ui::AlgorithmRunner* _ui;
  bool _droppingFavorite;

public:
  explicit AlgorithmRunner(QWidget* parent = NULL);
  virtual ~AlgorithmRunner();

public slots:
  void setGraph(tlp::Graph*);

protected slots:
  void setFilter(QString);
  void addFavorite(const QString& algName, const tlp::DataSet& data);

protected:
  bool eventFilter(QObject *, QEvent *);
};

class AlgorithmRunnerItem: public QWidget {
  Q_OBJECT
  Ui::AlgorithmRunnerItem* _ui;
  QString _pluginName;
  tlp::Graph* _graph;
  bool _localMode;
  QPointF _dragStartPosition;

public:
  explicit AlgorithmRunnerItem(QString pluginName, QWidget* parent = NULL);
  virtual ~AlgorithmRunnerItem();

  QString name() const;
  QString python() const;

protected:
  virtual void mousePressEvent(QMouseEvent* ev);
  virtual void mouseMoveEvent(QMouseEvent* ev);

public slots:
  void setGraph(tlp::Graph*);
  void setLocalMode(bool);

  void run(tlp::Graph* g = NULL);

protected slots:
  void afterRun(tlp::Graph*,tlp::DataSet);
};

#endif // ALGORITHMRUNNER_H
