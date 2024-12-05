// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LibrarySystem.h"  // Include the LibrarySystem header file
#include <QString>
#include <string>

LibrarySystem library;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->pushButtonPush, &QPushButton::clicked, this, &MainWindow::onPushButtonPushClicked);
    connect(ui->pushButtonPop, &QPushButton::clicked, this, &MainWindow::onPushButtonPopClicked);
    connect(ui->pushButtonPeek, &QPushButton::clicked, this, &MainWindow::onPushButtonPeekClicked);
    connect(ui->pushButtonEnqueue, &QPushButton::clicked, this, &MainWindow::onPushButtonEnqueueClicked);
    connect(ui->pushButtonDequeue, &QPushButton::clicked, this, &MainWindow::onPushButtonDequeueClicked);
    connect(ui->pushButtonPeekReservation, &QPushButton::clicked, this, &MainWindow::onPushButtonPeekReservationClicked);
    connect(ui->pushButtonState, &QPushButton::clicked, this, &MainWindow::onPushButtonStateClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Define the button click handlers (e.g., onPushButtonPushClicked)
void MainWindow::onPushButtonPushClicked() {
    QString bookTitle = ui->lineEditBook->text();  // Assume you have a QLineEdit for book title input
    if (!bookTitle.isEmpty()) {
        library.pushReturnedBook(bookTitle.toStdString());
        ui->lineEditBook->clear();  // Clear the input after use

        ui->textOutput->setText("Book \"" + bookTitle +  "\" added to returned books." );
    } else {
        ui->textOutput->setText("Please enter a book title.");  // Display a message if no title was entered
    }
}

void MainWindow::onPushButtonPopClicked() {
    library.popReturnedBook();
    ui->textOutput->setText("Removed the most recent book from the returned stack.");
}

void MainWindow::onPushButtonPeekClicked() {
    // Get the top book from the returned stack
    std::string topBook = library.peekReturnedBook();

    // Display the result in textOutput
    if (!topBook.empty()) {
        ui->textOutput->setText(QString::fromStdString("Top book in returned stack: " + topBook));
    } else {
        ui->textOutput->setText("No books in returned stack.");
    }
}




void MainWindow::onPushButtonEnqueueClicked() {
    QString reservationName = ui->lineEditReservation->text();  // Assume you have a QLineEdit for reservation input
    if (!reservationName.isEmpty()) {
        library.enqueueReservation(reservationName.toStdString());
        ui->lineEditReservation->clear();        // Clear the input after use

        ui->textOutput->setText("Reservation: "  + reservationName);
    } else {
        ui->textOutput->setText("Please enter a reservation name.");  // Display a message if no name was entered
    }
}

void MainWindow::onPushButtonDequeueClicked() {
    std::string nextReservation = library.getNextReservation();  // Get the next reservation

    if (!nextReservation.empty()) {  // Check if there is a reservation
        library.dequeueReservation();  // Remove the reservation from the queue
        ui->textOutput->setText(QString::fromStdString("Reservation \"" + nextReservation + "\" processed and removed from queue."));
    } else {
        ui->textOutput->setText("No reservations in queue to dequeue.");
    }
}



void MainWindow::onPushButtonPeekReservationClicked() {
    std::string nextReservation = library.getNextReservation();
    if(!nextReservation.empty()){
        ui->textOutput->setText(QString::fromStdString("Next reservation in queue: " + nextReservation));

    }else {
        ui->textOutput->setText("No Reservation in queue");
    }

}

void MainWindow::onPushButtonStateClicked() {
    std::string state = library.getState();  // Retrieve the current state as a string
    ui->textOutput->setText(QString::fromStdString(state));  // Display in the text output widget
}
