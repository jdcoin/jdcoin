// Copyright (c) 2017-2020 The JDCOIN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZJDCCONTROLDIALOG_H
#define ZJDCCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zjdc/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZJdcControlDialog;
}

class CZJdcControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZJdcControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZJdcControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZJdcControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZJdcControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZJdcControlDialog(QWidget *parent);
    ~ZJdcControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZJdcControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZJdcControlWidgetItem;

private Q_SLOTS:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZJDCCONTROLDIALOG_H
