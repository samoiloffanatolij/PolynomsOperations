#ifndef MESSAGE_H
#define MESSAGE_H

#endif // MESSAGE_H

#include "mainwindow.h"
#include "global.h"
#include <QTextEdit>
#include <iostream>
#include <string>
#include <vector>
#include <QFileDialog>
#include <algorithm>
#include <QMessageBox>
#include <math.h>

void MainWindow::NoPolinom(int ans){
    QMessageBox msgBox;
    string text = to_string(ans);
    QString qtext = "";
    for(int i = 0; i < text.size(); ++i){
        qtext += text[i];
    }
    msgBox.setText("There are no polinom with number " + qtext);
    msgBox.exec();
}


void MainWindow::outNoText(){
    QMessageBox msgBox;
    msgBox.setText("Please, enter deriving var");
    msgBox.exec();
}


void errorSituation(int error){
    QMessageBox msgBox;
    string text = to_string(error + 1);
    QString qtext = "";
    for(int i = 0; i < text.size(); ++i){
        qtext += text[i];
    }
    msgBox.setText("Invalid symbol in " + qtext + " position.");
    msgBox.exec();
}


void MainWindow::uncorrectPolinom(int ans){
    QMessageBox msgBox;
    string text = to_string(ans);
    QString qtext = "";
    for(int i = 0; i < text.size(); ++i){
        qtext += text[i];
    }
    msgBox.setText("You can't use " + qtext + " polinom for this task (there are no variables in it).");
    msgBox.exec();
}


void MainWindow::onlyNum(int row, int column){
    QMessageBox msgBox;
    string text = to_string(row);
    QString qtext1 = "";
    for(int i = 0; i < text.size(); ++i){
        qtext1 += text[i];
    }
    text = to_string(column);
    QString qtext2 = "";
    for(int i = 0; i < text.size(); ++i){
        qtext2 += text[i];
    }
    msgBox.setText("You can enter only numbers (row " + qtext1 + " column " + qtext2 + ").");
    msgBox.exec();
}


void MainWindow::noNum(int row, int column){
    QMessageBox msgBox;
    string text = to_string(row);
    QString qtext1 = "";
    for(int i = 0; i < text.size(); ++i){
        qtext1 += text[i];
    }
    text = to_string(column);
    QString qtext2 = "";
    for(int i = 0; i < text.size(); ++i){
        qtext2 += text[i];
    }
    msgBox.setText("You must enter number (row " + qtext1 + " column " + qtext2 + ").");
    msgBox.exec();
}


void MainWindow::outAnsInPoint(double ans){
    QMessageBox msgBox;
    string text = to_string(ans);
    QString qtext = "";
    for(int i = 0; i < text.size(); ++i){
        qtext += text[i];
    }
    msgBox.setText("Answer in this point : " + qtext);
    msgBox.exec();
}


int MainWindow::outAnsMultiple(string ans){
    QMessageBox msgBox;
    QString qtext = "";
    for(int i = 0; i < ans.size(); ++i){
        qtext+=ans[i];
    }
    msgBox.setText("Final polinom : " + qtext + ". Do you want to save it?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save) {
        return 1;
    }
    else {
        return 0;
    }
}


int MainWindow::outAnsDeriv(string ans){
    QMessageBox msgBox;
    QString qtext = "";
    for(int i = 0; i < ans.size(); ++i){
        qtext+=ans[i];
    }
    msgBox.setText("Final polinom : " + qtext + ". Do you want to save it?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save) {
        return 1;
    }
    else {
        return 0;
    }
}


int MainWindow::outSumm(string ans){
    QMessageBox msgBox;
    QString qtext = "";
    for(int i = 0; i < ans.size(); ++i){
        qtext+=ans[i];
    }
    msgBox.setText("Final polinom : " + qtext + ". Do you want to save it?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save) {
        return 1;
    }
    else {
        return 0;
    }
}


void  MainWindow::onlyAlfabet(){
    QMessageBox msgBox;
    msgBox.setText("You can use only english variables that used in your polinom, and it must been only one.");
    msgBox.exec();
}


void  MainWindow::outNotCorrectDeriv(){
    QMessageBox msgBox;
    msgBox.setText("Number must be more then 0.");
    msgBox.exec();
}


void MainWindow::uncorrectDivide(int ans){
    QMessageBox msgBox;
    string text = to_string(ans);
    QString qtext = "";
    for(int i = 0; i < text.size(); ++i){
        qtext += text[i];
    }
    msgBox.setText(qtext + " polinom has more than 1 variable, but for divide it must have less than 2.");
    msgBox.exec();
}


void MainWindow::notSimilarDivide(){
    QMessageBox msgBox;
    msgBox.setText("Polinoms must have similar variables for dividing.");
    msgBox.exec();
}


int MainWindow::outAnsDivide(string new_polinom, string now){
    int state = 0;
    QMessageBox msgBox;
    QString qtext = "";
    for(int i = 0; i < new_polinom.size(); ++i){
        qtext+=new_polinom[i];
    }
    msgBox.setText("The whole part of answer : " + qtext + ". Do you want to save it?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Save) {
        state += 1;
    }
    qtext = "";
    for(int i = 0; i < now.size(); ++i){
        qtext+=now[i];
    }
    msgBox.setText("The remains of answer : " + qtext + ". Do you want to save it?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    ret = msgBox.exec();
    if(ret == QMessageBox::Save) {
        state += 2;
    }
    return state;
}


void MainWindow::cantDivideZero(){
    QMessageBox msgBox;
    msgBox.setText("You can't divide on zero");
    msgBox.exec();
}


void MainWindow::uncorrectFinding(){
    QMessageBox msgBox;
    msgBox.setText("polinom has more than 1 variable, but for finding answers it must have only 1 variable.");
    msgBox.exec();
}


void MainWindow::outAllAswers(vector<int> ans){
    QMessageBox msgBox;
    if(ans.size() == 0){
        msgBox.setText("No answers.");
    }
    else{
        string res = "";
        for(int i = 0; i < ans.size(); ++i){
            res += to_string(ans[i]);
            res += " ";
        }
        QString text = "";
        for(int i = 0; i < res.size(); ++i){
            text += res[i];
        }
        msgBox.setText("All answers: " + text);
    }
    msgBox.exec();
}
