from PySide6.QtWidgets import QApplication, QPushButton, QMainWindow
from PySide6.QtGui import QPainter, QPolygon, QRegion
from PySide6.QtCore import Qt, QPoint
from PySide6.QtGui import QPixmap

class TriangleButton(QPushButton):
    def __init__(self, text="", parent=None):
        super().__init__(text, parent)
        self.setText(text)
        self.setFlat(True)  # Remove the default button border

        # Define the triangular shape using QPolygon
        self.triangle_polygon = QPolygon([
            QPoint(0, 100),   # Bottom-left
            QPoint(50, 0),    # Top-center
            QPoint(100, 100)  # Bottom-right
        ])

        # Set the mask for the button
        self.setMask(QRegion(self.triangle_polygon))

    def paintEvent(self, event):
        # Custom painting for the triangular button
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)

        # Draw the triangle shape
        painter.setBrush(Qt.blue)
        painter.drawPolygon(self.triangle_polygon)

        # Draw the text
        painter.setPen(Qt.white)
        painter.drawText(self.rect(), Qt.AlignCenter, self.text())

        painter.end()

    def sizeHint(self):
        return self.triangle_polygon.boundingRect().size()

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Irregular Button Example")

        # Create and place the triangle button
        self.triangle_button = TriangleButton("Click Me", self)
        self.triangle_button.setGeometry(50, 50, 100, 100)
        self.triangle_button.clicked.connect(self.on_button_clicked)

    def on_button_clicked(self):
        print("Triangle button clicked!")

if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    window.resize(200, 200)
    app.exec()
