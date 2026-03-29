#pragma once
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include "Structs.h"

void writeVTU(
    const std::string& filename,
    const grid& g,
    const SystemOfEquation& SOE
) {
    std::ofstream file(filename);
    file << std::fixed << std::setprecision(6);

    file << "<?xml version=\"1.0\"?>\n";
    file << "<VTKFile type=\"UnstructuredGrid\" version=\"0.1\" byte_order=\"LittleEndian\">\n";
    file << "  <UnstructuredGrid>\n";
    file << "    <Piece NumberOfPoints=\"" << g.nN
        << "\" NumberOfCells=\"" << g.nE << "\">\n";

    // ================= POINT DATA (temperatura) =================
    file << "      <PointData Scalars=\"Temperature\">\n";
    file << "        <DataArray type=\"Float64\" Name=\"Temperature\" format=\"ascii\">\n";
    for (int i = 0; i < g.nN; ++i)
        file << SOE.t[i] << " ";
    file << "\n        </DataArray>\n";
    file << "      </PointData>\n";

    // ================= POINTS =================
    file << "      <Points>\n";
    file << "        <DataArray type=\"Float64\" NumberOfComponents=\"3\" format=\"ascii\">\n";
    for (int i = 0; i < g.nN; ++i) {
        file << g.node[i].x << " "
            << g.node[i].y << " "
            << 0.0 << " ";
    }
    file << "\n        </DataArray>\n";
    file << "      </Points>\n";

    // ================= CELLS =================
    file << "      <Cells>\n";

    // --- connectivity
    file << "        <DataArray type=\"Int32\" Name=\"connectivity\" format=\"ascii\">\n";
    for (int e = 0; e < g.nE; ++e) {
        for (int i = 0; i < 4; ++i)
            file << g.element[e].ID[i] - 1 << " ";
    }
    file << "\n        </DataArray>\n";

    // --- offsets
    file << "        <DataArray type=\"Int32\" Name=\"offsets\" format=\"ascii\">\n";
    int offset = 0;
    for (int e = 0; e < g.nE; ++e) {
        offset += 4;
        file << offset << " ";
    }
    file << "\n        </DataArray>\n";

    // --- types (VTK_QUAD = 9)
    file << "        <DataArray type=\"UInt8\" Name=\"types\" format=\"ascii\">\n";
    for (int e = 0; e < g.nE; ++e)
        file << "9 ";
    file << "\n        </DataArray>\n";

    file << "      </Cells>\n";
    file << "    </Piece>\n";
    file << "  </UnstructuredGrid>\n";
    file << "</VTKFile>\n";

    file.close();
}


void writePVD(
    const std::string& filename,
    const std::vector<std::string>& vtuFiles,
    const std::vector<double>& timesteps
) {
    std::ofstream file(filename);

    file << "<?xml version=\"1.0\"?>\n";
    file << "<VTKFile type=\"Collection\" version=\"0.1\" byte_order=\"LittleEndian\">\n";
    file << "  <Collection>\n";

    for (size_t i = 0; i < vtuFiles.size(); ++i) {
        file << "    <DataSet timestep=\""
            << timesteps[i]
            << "\" group=\"\" part=\"0\" file=\""
            << vtuFiles[i]
            << "\"/>\n";
    }

    file << "  </Collection>\n";
    file << "</VTKFile>\n";

    file.close();
}


void writeTemperatureMinMax(
    const std::string& filename,
    const std::vector<double>& t,
    double time,
    bool writeHeader = false
) {
    std::ofstream file;

    if (writeHeader)
        file.open(filename, std::ios::out);
    else
        file.open(filename, std::ios::app);

    if (!file.is_open())
        return;

    file << std::fixed << std::setprecision(6);

    if (writeHeader) {
        file << "Czas   Tmin   Tmax\n";
    }

    auto minmax = std::minmax_element(t.begin(), t.end());
    double tmin = *minmax.first;
    double tmax = *minmax.second;

    file << time << " "
        << tmin << " "
        << tmax << "\n";

    file.close();
}