🧬 BioGridClassifier (C / MinGW)

📌 Overview

A C console application (MinGW / gcc) that reads a matrix of integers from Veri.txt and classifies each value as Plant, Bug, Fly, or Flea according to given thresholds. The file may contain variable rows and columns with values separated by a single space.

🔢 Classification Rules
Range	Class
1–9	Plant
10–20	Bug
21–50	Fly
51–99	Flea

All numbers are integers in the range [1, 99].

🔮 Future Improvements

Export labeled grid to Output.txt

Heatmap/legend visualization (ASCII)

Add unit tests (CTest) and CI workflow

📜 License

This project is licensed under the MIT License.
