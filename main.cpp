#include <iostream>
#include <fstream>
#include <vector>

#include "com/here/hdlm/protobuf/schema/v1/road/topologygeometry/topology_geometry.pb.h"

namespace
{
namespace hd_tg = com::here::hdlm::protobuf::schema::v1::road::topologygeometry;

void print_all_node_ids( const hd_tg::TopologyLayerTile& tile )
{
    std::cout << "Tile with id: " << tile.here_tile_id( ) << " contains nodes: " << std::endl;
    for ( const auto& node : tile.nodes_in_tile( ) )
    {
        std::cout << "node id: " << node.node_id( ) << std::endl;
    }
}

const hd_tg::Node* find_node_by_id( const hd_tg::TopologyLayerTile& tile, uint32_t id )
{
    for ( const auto& node : tile.nodes_in_tile( ) )
    {
        if ( node.node_id( ) == id )
        {
            return &node;
        }
    }
    return nullptr;
}

} // unnamed namespace

int main( int argc, char* argv[] )
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // TODO: make configurable or readable from commandline
    std::fstream s( "./map-data/here-hdlm-protobuf-weu-2/topology-geometry/327031896" );

    hd_tg::TopologyLayerTile tile;
    tile.ParseFromIstream( &s );

    print_all_node_ids( tile );
    return 0;
}