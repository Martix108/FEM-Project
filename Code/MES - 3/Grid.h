#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "GaussP.h"
#include "Structs.h"


std::vector<int> cegla = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 99, 100, 101, 102, 103, 109, 110, 111, 112, 113, 119, 120, 121, 122, 123, 129, 130, 131, 132, 133, 139, 140, 141, 142, 143, 149, 150, 151, 152, 153, 159, 160, 161, 162, 163, 169, 170, 171, 172, 173, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 279, 280, 281, 282, 283, 289, 290, 291, 292, 293, 299, 300, 301, 302, 303, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 329, 330, 331, 332, 333, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 359, 360, 361, 362, 363, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 389, 390, 391, 392, 393, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 419, 420, 421, 422, 423, 429, 430, 431, 432, 433, 439, 440, 441, 442, 443, 449, 450, 451, 452, 453, 459, 460, 461, 462, 463, 469, 470, 471, 472, 473, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 609, 610, 611, 612, 613, 619, 620, 621, 622, 623, 629, 630, 631, 632, 633, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 659, 660, 661, 662, 663, 669, 670, 671, 672, 673, 674, 675, 676, 677, 678, 679, 680, 681, 682, 683, 689, 690, 691, 692, 693, 699, 700, 701, 702, 703, 704, 705, 706, 707, 708, 709, 710, 711, 712, 713, 719, 720, 721, 722, 723, 729, 730, 731, 732, 733, 739, 740, 741, 742, 743, 749, 750, 751, 752, 753, 759, 760, 761, 762, 763, 769, 770, 771, 772, 773, 779, 780, 781, 782, 783, 789, 790, 791, 792, 793, 799, 800, 801, 802, 803, 809, 810, 811, 812, 813, 814, 815, 816, 817, 818, 819, 820, 821, 822, 823, 824, 825, 826, 827, 828, 829, 830, 831, 832, 833, 834, 835, 836, 837, 838, 839, 840, 841, 842, 843, 844, 845, 846, 847, 848, 849, 850, 851, 852, 853, 854, 855, 856, 857, 858, 859, 860, 861, 862, 863, 864, 865, 866, 867, 868, 869, 870, 871, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881, 882, 883, 884, 885, 886, 887, 888, 889, 890, 891, 892, 893, 894, 895, 896, 897, 898, 899, 900 };
std::vector<int> cegla_big = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 102, 103, 104, 105, 106, 107, 108, 109, 118, 119, 120, 121, 122, 123, 132, 133, 134, 135, 136, 137, 138, 139, 148, 149, 150, 151, 152, 153, 162, 163, 164, 165, 166, 167, 168, 169, 178, 179, 180, 181, 182, 183, 192, 193, 194, 195, 196, 197, 198, 199, 208, 209, 210, 211, 212, 213, 222, 223, 224, 225, 226, 227, 228, 229, 238, 239, 240, 241, 242, 243, 252, 253, 254, 255, 256, 257, 258, 259, 268, 269, 270, 271, 272, 273, 282, 283, 284, 285, 286, 287, 288, 289, 298, 299, 300, 301, 302, 303, 312, 313, 314, 315, 316, 317, 318, 319, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 582, 583, 584, 585, 586, 587, 588, 589, 598, 599, 600, 601, 602, 603, 612, 613, 614, 615, 616, 617, 618, 619, 628, 629, 630, 631, 632, 633, 642, 643, 644, 645, 646, 647, 648, 649, 658, 659, 660, 661, 662, 663, 672, 673, 674, 675, 676, 677, 678, 679, 688, 689, 690, 691, 692, 693, 702, 703, 704, 705, 706, 707, 708, 709, 718, 719, 720, 721, 722, 723, 732, 733, 734, 735, 736, 737, 738, 739, 748, 749, 750, 751, 752, 753, 762, 763, 764, 765, 766, 767, 768, 769, 778, 779, 780, 781, 782, 783, 792, 793, 794, 795, 796, 797, 798, 799, 808, 809, 810, 811, 812, 813, 814, 815, 816, 817, 818, 819, 820, 821, 822, 823, 824, 825, 826, 827, 828, 829, 830, 831, 832, 833, 834, 835, 836, 837, 838, 839, 840, 841, 842, 843, 844, 845, 846, 847, 848, 849, 850, 851, 852, 853, 854, 855, 856, 857, 858, 859, 860, 861, 862, 863, 864, 865, 866, 867, 868, 869, 870, 871, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881, 882, 883, 884, 885, 886, 887, 888, 889, 890, 891, 892, 893, 894, 895, 896, 897, 898, 899, 900 };
std::vector<int> siatka = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279, 280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499, 500, 501, 502, 503, 504, 505, 506, 507, 508, 509, 510, 511, 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654, 655, 656, 657, 658, 659, 660, 661, 662, 663, 664, 665, 666, 667, 668, 669, 670, 671, 672, 673, 674, 675, 676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 686, 687, 688, 689, 690, 691, 692, 693, 694, 695, 696, 697, 698, 699, 700, 701, 702, 703, 704, 705, 706, 707, 708, 709, 710, 711, 712, 713, 714, 715, 716, 717, 718, 719, 720, 721, 722, 723, 724, 725, 726, 727, 728, 729, 730, 731, 732, 733, 734, 735, 736, 737, 738, 739, 740, 741, 742, 743, 744, 745, 746, 747, 748, 749, 750, 751, 752, 753, 754, 755, 756, 757, 758, 759, 760, 761, 762, 763, 764, 765, 766, 767, 768, 769, 770, 771, 772, 773, 774, 775, 776, 777, 778, 779, 780, 781, 782, 783, 784, 785, 786, 787, 788, 789, 790, 791, 792, 793, 794, 795, 796, 797, 798, 799, 800, 801, 802, 803, 804, 805, 806, 807, 808, 809, 810, 811, 812, 813, 814, 815, 816, 817, 818, 819, 820, 821, 822, 823, 824, 825, 826, 827, 828, 829, 830, 831, 832, 833, 834, 835, 836, 837, 838, 839, 840, 841, 842, 843, 844, 845, 846, 847, 848, 849, 850, 851, 852, 853, 854, 855, 856, 857, 858, 859, 860, 861, 862, 863, 864, 865, 866, 867, 868, 869, 870, 871, 872, 873, 874, 875, 876, 877, 878, 879, 880, 881, 882, 883, 884, 885, 886, 887, 888, 889, 890, 891, 892, 893, 894, 895, 896, 897, 898, 899, 900 };

double CEGLA_CONDUCTIVITY = 1.331;
double CEGLA_DENSITY = 2083.0;
double CEGLA_SPECIFIC_HEAT = 921.0;

double POWIETRZE_CONDUCTIVITY = 0.025;
double POWIETRZE_DENSITY = 1.29;
double POWIETRZE_SPECIFIC_HEAT = 1004.0;



bool loadGridData(const std::string& filename, GlobalData& global, grid& g) {
	std::ifstream odczyt(filename);
	if (!odczyt.is_open()) {
		std::cout << "Nie mozna otworzyc pliku: " << filename << std::endl;
		return false;
	}

	std::string tmp;

	odczyt >> tmp >> global.SimulationTime;
	odczyt >> tmp >> global.SimulationStepTime;
	odczyt >> tmp >> global.Conductivity;
	odczyt >> tmp >> global.Alfa;
	odczyt >> tmp >> global.Tot;
	odczyt >> tmp >> global.InitialTemp;
	odczyt >> tmp >> global.Density;
	odczyt >> tmp >> global.SpecificHeat;
	odczyt >> tmp >> global.nN;
	odczyt >> tmp >> global.nE;

	g.nN = global.nN;
	g.nE = global.nE;

	g.node.resize(g.nN);
	g.element.resize(g.nE);

	//Wczytywanie *Node
	odczyt >> tmp;
	for (int i = 0; i < g.nN; i++) {
		int id; char c; double x, y;
		odczyt >> id >> c >> x >> c >> y;
		g.node[id - 1] = { x, y, 0};
	}

	//Wczytywanie *Element
	odczyt >> tmp;
	odczyt >> tmp;
	for (int i = 0; i < g.nE; i++) {
		int id, n1, n2, n3, n4; char c;
		odczyt >> id >> c >> n1 >> c >> n2 >> c >> n3 >> c >> n4;
		g.element[id - 1].globalID = id;
		g.element[id - 1].ID = { n1,n2,n3,n4 };
	}

	//Wczytywanie *BC
	odczyt >> tmp;
	std::string line, BC;
	std::getline(odczyt, line);
	if (line.empty()) std::getline(odczyt, line);
	std::stringstream ss(line);

	while (std::getline(ss, BC, ',')) {
		int id = std::stoi(BC);
		g.node[id - 1].BC = true;
	}
	
	return true;
}


template <typename GaussType>
void calculate_dN_dKsi(ElemUniv& EU, const GaussType& gauss) {
	int pointIndex = 0;

	for (int i = 0; i < gauss.nodes.size(); i++) {
		for (int j = 0; j < gauss.nodes.size(); j++) {
			double eta = gauss.nodes[i];

			EU.dN_dKsi[pointIndex][0] = -0.25 * (1 - eta);
			EU.dN_dKsi[pointIndex][1] = 0.25 * (1 - eta);
			EU.dN_dKsi[pointIndex][2] = 0.25 * (1 + eta);
			EU.dN_dKsi[pointIndex][3] = -0.25 * (1 + eta);

			pointIndex++;
		}
	}
}


template<typename GaussType>
void calculate_dN_dEta(ElemUniv& EU, const GaussType& gauss) {
	int pointIndex = 0;

	for (int i = 0; i < gauss.nodes.size(); i++) {
		for (int j = 0; j < gauss.nodes.size(); j++) {
			double ksi = gauss.nodes[j];

			EU.dN_dEta[pointIndex][0] = -0.25 * (1 - ksi);
			EU.dN_dEta[pointIndex][1] = -0.25 * (1 + ksi);
			EU.dN_dEta[pointIndex][2] = 0.25 * (1 + ksi);
			EU.dN_dEta[pointIndex][3] = 0.25 * (1 - ksi);

			pointIndex++;
		}
	}
}


template<typename GaussType>
void calculateN(ElemUniv& EU, const GaussType& gauss) {
	int pointIndex = 0;

	for (int i = 0; i < gauss.nodes.size(); i++) {
		for (int j = 0; j < gauss.nodes.size(); j++) {
			double ksi = gauss.nodes[j];
			double eta = gauss.nodes[i];

			EU.N[pointIndex][0] = 0.25 * (1 - ksi) * (1 - eta);
			EU.N[pointIndex][1] = 0.25 * (1 + ksi) * (1 - eta);
			EU.N[pointIndex][2] = 0.25 * (1 + ksi) * (1 + eta);
			EU.N[pointIndex][3] = 0.25 * (1 - ksi) * (1 + eta);

			pointIndex++;
		}
	}
}


template<typename GaussType>
void calculateSurfaceN(ElemUniv& EU, const GaussType& gauss) {
	//Bok 1: eta = -1
	for (int i = 0; i < gauss.nodes.size(); i++) {
		double ksi = gauss.nodes[i];
		double eta = -1.0;
		EU.surface[0].N[i] = {
			0.25 * (1 - ksi) * (1 - eta),
			0.25 * (1 + ksi) * (1 - eta),
			0.25 * (1 + ksi) * (1 + eta),
			0.25 * (1 - ksi) * (1 + eta)
		};
	}

	//Bok 2: ksi = 1
	for (int i = 0; i < gauss.nodes.size(); i++) {
		double ksi = 1.0;
		double eta = gauss.nodes[i];
		EU.surface[1].N[i] = {
			0.25 * (1 - ksi) * (1 - eta),
			0.25 * (1 + ksi) * (1 - eta),
			0.25 * (1 + ksi) * (1 + eta),
			0.25 * (1 - ksi) * (1 + eta)
		};
	}

	//Bok 3: eta = 1
	for (int i = 0; i < gauss.nodes.size(); i++) {
		double ksi = gauss.nodes[i];
		double eta = 1.0;
		EU.surface[2].N[i] = {
			0.25 * (1 - ksi) * (1 - eta),
			0.25 * (1 + ksi) * (1 - eta),
			0.25 * (1 + ksi) * (1 + eta),
			0.25 * (1 - ksi) * (1 + eta)
		};
	}

	//Bok 4: ksi = -1
	for (int i = 0; i < gauss.nodes.size(); i++) {
		double ksi = -1.0;
		double eta = gauss.nodes[i];
		EU.surface[3].N[i] = {
			0.25 * (1 - ksi) * (1 - eta),
			0.25 * (1 + ksi) * (1 - eta),
			0.25 * (1 + ksi) * (1 + eta),
			0.25 * (1 - ksi) * (1 + eta)
		};
	}
}


void calculateData(int nPC, const grid& g, element& el, const ElemUniv& EU) {
	if (el.jakobian.size() < nPC)
		el.jakobian.resize(nPC);
	if (el.dN_dx_dy.size() < nPC)
		el.dN_dx_dy.resize(nPC);

	for (int pc = 0; pc < nPC; pc++) {		//Każdy punkt całkowania
		double dx_dKsi = 0.0, dy_dKsi = 0.0;
		double dx_dEta = 0.0, dy_dEta = 0.0;

		for (int i = 0; i < 4; i++) {		//4 węzły dla 1 elementu
			int nodeId = el.ID[i] - 1;
			double x = g.node[nodeId].x;
			double y = g.node[nodeId].y;

			dx_dKsi += EU.dN_dKsi[pc][i] * x;
			dy_dKsi += EU.dN_dKsi[pc][i] * y;
			dx_dEta += EU.dN_dEta[pc][i] * x;
			dy_dEta += EU.dN_dEta[pc][i] * y;
		}

		el.jakobian[pc].J[0][0] = dx_dKsi;
		el.jakobian[pc].J[0][1] = dy_dKsi;
		el.jakobian[pc].J[1][0] = dx_dEta;
		el.jakobian[pc].J[1][1] = dy_dEta;

		double detJ = (dx_dKsi * dy_dEta) - (dx_dEta * dy_dKsi);
		el.jakobian[pc].detJ = detJ;

		double invDet = 1.0 / detJ;
		el.jakobian[pc].J1[0][0] = dy_dEta * invDet;
		el.jakobian[pc].J1[0][1] = -dy_dKsi * invDet;
		el.jakobian[pc].J1[1][0] = -dx_dEta * invDet;
		el.jakobian[pc].J1[1][1] = dx_dKsi * invDet;

		el.dN_dx_dy[pc].dN_dx.resize(4);
		el.dN_dx_dy[pc].dN_dy.resize(4);

		for (int i = 0; i < 4; i++) {
			double dN_dKsi = EU.dN_dKsi[pc][i];
			double dN_dEta = EU.dN_dEta[pc][i];

			el.dN_dx_dy[pc].dN_dx[i] = el.jakobian[pc].J1[0][0] * dN_dKsi + el.jakobian[pc].J1[0][1] * dN_dEta;
			el.dN_dx_dy[pc].dN_dy[i] = el.jakobian[pc].J1[1][0] * dN_dKsi + el.jakobian[pc].J1[1][1] * dN_dEta;
		}
	}
}


template<typename GaussType>
void calculateH(element& el, GlobalData& global, const GaussType& gauss) {
	double H_pc[4][4];
	int pc = 0;

	//Liczenie H
	for (int a = 0; a < gauss.coefficients.size(); a++) {
		for (int b = 0; b < gauss.coefficients.size(); b++) {
			//Współczynniki do wymnożenia
			double w1 = gauss.coefficients[a];		//Po ksi
			double w2 = gauss.coefficients[b];		//Po eta

			//Liczenie H_pc
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					
					H_pc[i][j] = (el.dN_dx_dy[pc].dN_dx[i] * el.dN_dx_dy[pc].dN_dx[j]) +
						(el.dN_dx_dy[pc].dN_dy[i] * el.dN_dx_dy[pc].dN_dy[j]);

					// Projekt
					//if (std::find(siatka.begin(), siatka.end(), el.globalID) == siatka.end()) {
					//if (std::find(cegla.begin(), cegla.end(), el.globalID) == cegla.end()) {
					if (std::find(cegla_big.begin(), cegla_big.end(), el.globalID) == cegla_big.end()) {
						//Powietrze
						H_pc[i][j] *= POWIETRZE_CONDUCTIVITY * el.jakobian[pc].detJ;
					}
					else {
						//Cegła
						H_pc[i][j] *= CEGLA_CONDUCTIVITY * el.jakobian[pc].detJ;
					}
					

					//H_pc[i][j] *= global.Conductivity * el.jakobian[pc].detJ;
					H_pc[i][j] *= w1 * w2;
					el.H[i][j] += H_pc[i][j];
				}
			}

			pc++;
		}
	}
}


template<typename GaussType>
void calculateHbc(element& el, const grid& g, const GlobalData& global, const ElemUniv& EU, const GaussType& gauss) {
	//Tablica boków (id do punktów - element.ID - na każdej ścianie)
	const int sides[4][2] = {
		{0, 1}, {1, 2}, {2, 3}, {3, 0}
	};
	
	//Dla każdej ściany
	for (int side = 0; side < 4; side++) {
		int p1 = el.ID[sides[side][0]] - 1;
		int p2 = el.ID[sides[side][1]] - 1;
		
		//Jeżeli każdy punkt ma warunek brzegowy
		if (g.node[p1].BC && g.node[p2].BC) {
			//Obliczenie detJ
			double dx = g.node[p2].x - g.node[p1].x;
			double dy = g.node[p2].y - g.node[p1].y;
			double detJ = sqrt(dx * dx + dy * dy) / 2.0;

			//Dla każdego punktu całkowania
			for (int i = 0; i < gauss.nodes.size(); i++) {
				for (int j = 0; j < 4; j++) {
					for (int m = 0; m < 4; m++) {
						el.Hbc[j][m] += global.Alfa * EU.surface[side].N[i][j] * EU.surface[side].N[i][m] * detJ * gauss.coefficients[i];
					}
				}
			}
		}
	}
}


template<typename GaussType>
void calculateP(element& el, const grid& g, const GlobalData& global, const ElemUniv& EU, const GaussType& gauss) {
	//Tablica boków (id do punktów - element.ID - na każdej ścianie)
	const int sides[4][2] = {
		{0, 1}, {1, 2}, {2, 3}, {3, 0}
	};

	//Dla każdej ściany
	for (int side = 0; side < 4; side++) {
		int p1 = el.ID[sides[side][0]] - 1;
		int p2 = el.ID[sides[side][1]] - 1;

		//Jeżeli każdy punkt ma warunek brzegowy
		if (g.node[p1].BC && g.node[p2].BC) {
			//Obliczenie detJ
			double dx = g.node[p2].x - g.node[p1].x;
			double dy = g.node[p2].y - g.node[p1].y;
			double detJ = sqrt(dx * dx + dy * dy) / 2.0;

			//Dla każdego punktu całkowania
			for (int i = 0; i < gauss.nodes.size(); i++) {
				for (int j = 0; j < 4; j++) {
					el.P[j] += global.Alfa * EU.surface[side].N[i][j] * global.Tot * detJ * gauss.coefficients[i];
				}
			}
		}
	}
}


template<typename GaussType>
void calculateC(element& el, const ElemUniv& EU, const GlobalData& global, const GaussType& gauss) {
	int pc = 0;
	
	for (int a = 0; a < gauss.coefficients.size(); a++) {
		for (int b = 0; b < gauss.coefficients.size(); b++) {
			double w1 = gauss.coefficients[a];		//Po ksi
			double w2 = gauss.coefficients[b];		//Po eta

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {

					//Projekt
					//if (std::find(siatka.begin(), siatka.end(), el.globalID) == siatka.end()) {
					//if (std::find(cegla.begin(), cegla.end(), el.globalID) == cegla.end()) {
					if (std::find(cegla_big.begin(), cegla_big.end(), el.globalID) == cegla_big.end()) {
						//Powietrze
						el.C[i][j] += POWIETRZE_SPECIFIC_HEAT * POWIETRZE_DENSITY * EU.N[pc][i] * EU.N[pc][j] * el.jakobian[pc].detJ * w1 * w2;
					}
					else {
						// Cegła
						el.C[i][j] += CEGLA_SPECIFIC_HEAT * CEGLA_DENSITY * EU.N[pc][i] * EU.N[pc][j] * el.jakobian[pc].detJ * w1 * w2;
					}
					
					//el.C[i][j] += global.SpecificHeat * global.Density * EU.N[pc][i] * EU.N[pc][j] * el.jakobian[pc].detJ * w1 * w2;
				}
			}

			pc++;
		}
	}
}


void calculateHGlobal(element& el, SystemOfEquation& SOE) {
	for (int i = 0; i < el.ID.size(); i++) {
		for (int j = 0; j < el.ID.size(); j++) {
			SOE.Hg[el.ID[i] - 1][el.ID[j] - 1] += el.H[i][j];
			SOE.Hg[el.ID[i] - 1][el.ID[j] - 1] += el.Hbc[i][j];
		}
	}
}


void calculatePGlobal(element& el, SystemOfEquation& SOE) {
	for (int i = 0; i < el.ID.size(); i++) {
		SOE.Pg[el.ID[i] - 1] += el.P[i];
	}
}


void calculateCGlobal(element& el, SystemOfEquation& SOE) {
	for (int i = 0; i < el.ID.size(); i++) {
		for (int j = 0; j < el.ID.size(); j++) {
			SOE.Cg[el.ID[i] - 1][el.ID[j] - 1] += el.C[i][j];
		}
	}
}


void solve(SystemOfEquation& SOE, GlobalData& global) {
	//Macierz rozszerzona A|b, gdzie A = H, b = P
	std::vector<std::vector<double>> A(global.nN, std::vector<double>(global.nN + 1, 0.0));

	for (int i = 0; i < global.nN; i++) {
		for (int j = 0; j < global.nN; j++) {
			A[i][j] = SOE.Hg[i][j];
		}

		A[i][global.nN] = SOE.Pg[i];		//Prawa strona równania
	}

	//Eliminacja Gaussa
	for (int i = 0; i < global.nN; i++) {
		//Szukanie maksimum w kolumnie (pivoting)
		double maxEl = std::abs(A[i][i]);
		int maxRow = i;

		for (int k = i + 1; k < global.nN; k++) {
			if (std::abs(A[k][i]) > maxEl) {
				maxEl = std::abs(A[k][i]);
				maxRow = k;
			}
		}

		//Zamiana wierszy
		std::swap(A[i], A[maxRow]);

		//Zerowanie poniżej pivotu
		for (int k = i + 1; k < global.nN; k++) {
			double c = A[k][i] / A[i][i];

			for (int j = i; j <= global.nN; j++) {
				A[k][j] -= c * A[i][j];
			}
		}
	}

	//Podstawianie wsteczne
	for (int i = global.nN - 1; i >= 0; i--) {
		double sum = A[i][global.nN];

		for (int j = i + 1; j < global.nN; j++) {
			sum -= A[i][j] * SOE.t[j];
		}

		SOE.t[i] = sum / A[i][i];
	}
}


void solve_time(SystemOfEquation& SOE, GlobalData& global) {
	int n = global.nN;
	double dt = global.SimulationStepTime;
	double invdt = 1.0 / dt;

	// Zachowanie t0 (temperatury z poprzedniego kroku czasu)
	std::vector<double> t0 = SOE.t;

	//Macierz rozszerzona A|b
	std::vector<std::vector<double>> A(n, std::vector<double>(n + 1, 0.0));

	//A = H + (1/dt)*C  oraz  b = (1/dt)*C*t0 + P
	for (int i = 0; i < n; ++i) {
		double rhs = 0.0;  //Prawa strona b[i]

		for (int j = 0; j < n; ++j) {
			A[i][j] = SOE.Hg[i][j] + invdt * SOE.Cg[i][j];
			rhs += SOE.Cg[i][j] * t0[j];
		}

		A[i][n] = invdt * rhs + SOE.Pg[i];   //Zapis b[i]
	}

	//Eliminacja Gaussa z częściowym wyborem elementu głównego
	for (int i = 0; i < n; ++i) {

		//Wybór największego pivotu w kolumnie
		int maxRow = i;
		for (int k = i + 1; k < n; ++k)
			if (std::abs(A[k][i]) > std::abs(A[maxRow][i]))
				maxRow = k;

		std::swap(A[i], A[maxRow]);

		//Zerowanie poniżej pivotu
		for (int k = i + 1; k < n; ++k) {
			double c = A[k][i] / A[i][i];
			for (int j = i; j <= n; ++j)
				A[k][j] -= c * A[i][j];
		}
	}

	//Podstawianie wsteczne — wynik zapisujemy jako t1
	std::vector<double> t1(n, 0.0);

	for (int i = n - 1; i >= 0; --i) {
		double sum = A[i][n];
		for (int j = i + 1; j < n; ++j)
			sum -= A[i][j] * t1[j];

		t1[i] = sum / A[i][i];
	}

	//Nadpisanie temperatury na nowe wartości
	SOE.t = t1;
}