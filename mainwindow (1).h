#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_clicked();

    void on_save1_clicked();

    void updateList();

    void outAnsInPoint(double ans);

    void onlyNum(int row, int count);

    void noNum(int row, int column);

    void uncorrectPolinom(int ans);

    void NoPolinom(int ans);

    int outAnsMultiple(string ans);

    int outSumm(string ans);

    void onlyAlfabet();

    void outNotCorrectDeriv();

    int outAnsDeriv(string ans);

    void hideAll();

    void on_ans_point_clicked();

    void on_multiple_clicked();

    void on_deriv_clicked();

    void on_compare_clicked();

    void on_summ_clicked();

    void on_div_clicked();

    void on_all_answers_clicked();

    void on_back_clicked();

    void on_load_clicked();

    void on_save_clicked();

    void on_save1_2_clicked();

    void on_save1_9_clicked();

    void on_enter_var_cellChanged(int row, int column);

    void on_save1_3_clicked();

    void on_save1_4_clicked();

    void on_save1_5_clicked();

    void on_save1_6_clicked();

    void on_textEdit_14_textChanged();

    void on_save1_7_clicked();

    void on_save1_8_clicked();

    void outNoText();

    void on_save1_10_clicked();

    void uncorrectDivide(int x);

    void notSimilarDivide();

    int outAnsDivide(string new_polinom, string now);

    void on_delete_2_clicked();

    void on_pushButton_clicked();

    void cantDivideZero();

    void on_save1_11_clicked();

    void uncorrectFinding();

    void outAllAswers(vector<int> ans);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
