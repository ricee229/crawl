/**
 * @file
 * @brief "Overview" functionality
**/

#pragma once

#include <vector>

#include "stash.h"

void overview_clear();

void seen_notable_thing(dungeon_feature_type which_thing, const coord_def& pos);
bool move_notable_thing(const coord_def& orig, const coord_def& dest);
bool overview_knows_portal(branch_type portal);
int  overview_knows_num_portals(dungeon_feature_type portal);
void display_overview();
bool unnotice_feature(const level_pos &pos);
string overview_description_string(bool display);
void enter_branch(branch_type branch, level_id from);
void mark_corrupted_level(level_id li);
void seen_tracked_feature(dungeon_feature_type feat);
void explored_tracked_feature(dungeon_feature_type feat);

///////////////////////////////////////////////////////////
void set_level_exclusion_annotation(string str,
                                    level_id li = level_id::current());
void clear_level_exclusion_annotation(level_id li = level_id::current());
void set_unique_annotation(monster* mons,
                           const level_id level = level_id::current());
void remove_unique_annotation(monster* mons);

string get_level_annotation(level_id li = level_id::current(),
                            bool skip_excl = false, bool skip_uniq = false,
                            bool use_colour = false, int colour = LIGHTRED);

bool level_annotation_has(string str, level_id li = level_id::current());

void annotate_level(level_id li);
void do_annotate();
void clear_level_annotations(level_id li);

class writer;
class reader;
void marshallUniqueAnnotations(writer& outf);
void unmarshallUniqueAnnotations(reader& inf);
bool connected_branch_can_exist(branch_type br);
