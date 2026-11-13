
/* android::LoadedPackage::Load(android::Chunk const&, unsigned int) */

void __thiscall android::LoadedPackage::Load(LoadedPackage *this,Chunk *param_1,uint param_2)

{
  string *psVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  uchar *puVar6;
  int iVar7;
  ResStringPool *this_00;
  ResStringPool *pRVar8;
  vector<android::DynamicPackageEntry,std::allocator<android::DynamicPackageEntry>> *this_01;
  undefined4 *puVar9;
  ostream *poVar10;
  uint uVar11;
  int iVar12;
  unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>
  *this_02;
  uint *puVar13;
  int *piVar14;
  ulonglong *puVar15;
  void *pvVar16;
  char *pcVar17;
  __59 *p_Var18;
  int *piVar19;
  piecewise_construct_t *ppVar20;
  uint uVar21;
  __59 *extraout_r2;
  __59 *extraout_r2_00;
  __59 *p_Var22;
  IncFsFileMap *pIVar23;
  IncFsFileMap *pIVar24;
  piecewise_construct_t *ppVar25;
  undefined4 uVar26;
  piecewise_construct_t *ppVar27;
  char cVar28;
  int iVar29;
  void *pvVar30;
  LogMessage *this_03;
  int *piVar31;
  void *pvVar32;
  size_t __n;
  undefined4 uVar33;
  bool bVar34;
  piecewise_construct_t *ppVar35;
  IncFsFileMap *pIVar36;
  piecewise_construct_t *ppVar37;
  undefined4 local_130;
  IncFsFileMap *pIStack_12c;
  piecewise_construct_t *local_128;
  uint local_124;
  undefined4 local_120;
  piecewise_construct_t *local_118;
  IncFsFileMap *local_114;
  piecewise_construct_t *local_110 [2];
  piecewise_construct_t *local_108;
  IncFsFileMap *local_104;
  piecewise_construct_t *local_100;
  uint local_f8;
  undefined4 uStack_f4;
  void *local_f0;
  piecewise_construct_t *local_e8;
  undefined4 uStack_e4;
  void *local_e0;
  piecewise_construct_t *local_d8;
  IncFsFileMap *local_d4;
  piecewise_construct_t *local_d0;
  void *local_c8;
  undefined4 uStack_c4;
  undefined4 *local_c0;
  int iStack_bc;
  undefined4 local_b8;
  uchar *local_b0;
  IncFsFileMap *pIStack_ac;
  uchar *local_a8;
  piecewise_construct_t *local_a4;
  piecewise_construct_t *local_a0;
  IncFsFileMap *pIStack_9c;
  piecewise_construct_t *local_98;
  int iStack_94;
  undefined4 local_90;
  undefined8 local_88;
  piecewise_construct_t *local_80;
  int local_7c;
  int local_78;
  uint local_74;
  piecewise_construct_t *local_70;
  IncFsFileMap *local_6c;
  piecewise_construct_t *local_68 [2];
  uchar *local_60;
  undefined4 uStack_5c;
  undefined4 *puStack_58;
  int local_54;
  int local_50;
  uint local_4c;
  piecewise_construct_t *local_44 [2];
  int local_3c;
  
  local_3c = __stack_chk_guard;
  iVar7 = atrace_get_enabled_tags();
  if (iVar7 << 0x12 < 0) {
    atrace_begin_body("LoadedPackage::Load");
  }
  this_00 = operator_new(0x160);
  __aeabi_memclr8(this_00,0x160);
  ResStringPool::ResStringPool(this_00);
  ResStringPool::ResStringPool(this_00 + 0x5c);
  uVar26 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
  uVar33 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x8);
  uVar4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
  local_a8 = *(uchar **)(param_1 + 8);
  *(undefined4 *)(this_00 + 200) = 0xffffffff;
  *(undefined4 *)(this_00 + 0xbc) = 0;
  *(undefined4 *)(this_00 + 0xc1) = 0;
  *(undefined4 *)(this_00 + 0xbd) = 0;
  psVar1 = (string *)(this_00 + 0xb8);
  *(undefined4 *)psVar1 = 0;
  *(undefined4 *)(this_00 + 0xe0) = 0;
  *(undefined4 *)(this_00 + 0xe4) = 0x3f800000;
  *(undefined4 *)(this_00 + 0x15c) = 0x3f800000;
  pRVar8 = this_00 + 0xcc;
  *(undefined4 *)pRVar8 = 0;
  *(undefined4 *)(this_00 + 0xd0) = uVar26;
  *(undefined4 *)(this_00 + 0xd4) = uVar33;
  *(undefined4 *)(this_00 + 0xd8) = uVar4;
  *(undefined4 *)(this_00 + 0xdc) = 0;
  *(undefined4 *)(this_00 + 0xe8) = 0;
  *(undefined4 *)(this_00 + 0xec) = uVar26;
  *(undefined4 *)(this_00 + 0xf0) = uVar33;
  *(undefined4 *)(this_00 + 0xf4) = uVar4;
  *(undefined4 *)(this_00 + 0xf8) = 0;
  *(undefined4 *)(this_00 + 0xfc) = uVar26;
  *(undefined4 *)(this_00 + 0x100) = uVar33;
  *(undefined4 *)(this_00 + 0x104) = uVar4;
  *(undefined4 *)(this_00 + 0x108) = 0;
  *(undefined4 *)(this_00 + 0x10c) = uVar26;
  *(undefined4 *)(this_00 + 0x110) = uVar33;
  *(undefined4 *)(this_00 + 0x114) = uVar4;
  *(undefined4 *)(this_00 + 0x118) = 0;
  *(undefined4 *)(this_00 + 0x11c) = uVar26;
  *(undefined4 *)(this_00 + 0x120) = uVar33;
  *(undefined4 *)(this_00 + 0x124) = uVar4;
  this_01 = (vector<android::DynamicPackageEntry,std::allocator<android::DynamicPackageEntry>> *)
            (this_00 + 0x128);
  *(undefined4 *)this_01 = 0;
  *(undefined4 *)(this_00 + 300) = uVar26;
  *(undefined4 *)(this_00 + 0x130) = uVar33;
  *(undefined4 *)(this_00 + 0x134) = uVar4;
  *(undefined4 *)(this_00 + 0x138) = 0;
  *(undefined4 *)(this_00 + 0x13c) = uVar26;
  *(undefined4 *)(this_00 + 0x140) = uVar33;
  *(undefined4 *)(this_00 + 0x144) = uVar4;
  *(undefined4 *)(this_00 + 0x148) = 0;
  *(undefined4 *)(this_00 + 0x14c) = uVar26;
  *(undefined4 *)(this_00 + 0x150) = uVar33;
  *(undefined4 *)(this_00 + 0x154) = uVar4;
  *(undefined4 *)(this_00 + 0x158) = 0;
  local_b0 = *(uchar **)param_1;
  pIStack_ac = *(IncFsFileMap **)(param_1 + 4);
  if (*(ushort *)(local_b0 + 2) >> 2 < 0x47) {
    local_a8 = (uchar *)0x0;
    local_b0 = (uchar *)0x0;
    pIStack_ac = (IncFsFileMap *)0x0;
  }
  if (local_b0 == (uchar *)0x0) {
LAB_00055a68:
    iVar7 = android::base::ShouldLog(4,0);
    if (iVar7 != 0) {
      puVar9 = (undefined4 *)__errno();
      uVar26 = *puVar9;
      android::base::LogMessage::LogMessage
                ((LogMessage *)&local_60,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x1cd,4,0,
                 0xffffffff);
      poVar10 = (ostream *)android::base::LogMessage::stream();
      uVar21 = 0x21;
      pcVar17 = "RES_TABLE_PACKAGE_TYPE too small.";
LAB_00055ada:
      std::__put_character_sequence<char,std::char_traits<char>>(poVar10,pcVar17,uVar21);
      android::base::LogMessage::~LogMessage((LogMessage *)&local_60);
      *puVar9 = uVar26;
    }
LAB_00055a74:
    *(undefined4 *)this = 0;
  }
  else {
    if (pIStack_ac != (IncFsFileMap *)0x0) {
      local_88 = CONCAT44(local_88._4_4_,local_b0 + 0x120);
      local_60 = local_b0;
      if (((local_b0 < local_a8) || (local_a8 + 0x1000 < local_b0 + 0x120)) &&
         (iVar7 = incfs::IncFsFileMap::Verify(pIStack_ac,&local_60,(uchar **)&local_88,&local_a8),
         iVar7 == 0)) goto LAB_00055a68;
    }
    if ((param_2 & 1) != 0) {
      *(uint *)(this_00 + 0xd0) = *(uint *)(this_00 + 0xd0) | 1;
    }
    if ((int)(param_2 << 0x1d) < 0) {
      *(uint *)(this_00 + 0xd0) = *(uint *)(this_00 + 0xd0) | 4;
    }
    if ((int)(param_2 << 0x1c) < 0) {
      *(uint *)(this_00 + 0xd0) = *(uint *)(this_00 + 0xd0) | 10;
    }
    iVar7 = *(int *)(local_b0 + 8);
    *(int *)(this_00 + 200) = iVar7;
    if ((iVar7 == 0) || (((int)(param_2 << 0x1e) < 0 && (iVar7 == 0x7f)))) {
      *(uint *)(this_00 + 0xd0) = *(uint *)(this_00 + 0xd0) | 2;
    }
    if (0x11f < *(ushort *)(local_b0 + 2)) {
      if (0xff < *(uint *)(local_b0 + 0x11c)) {
        iVar7 = android::base::ShouldLog(4,0);
        if (iVar7 != 0) {
          puVar9 = (undefined4 *)__errno();
          uVar26 = *puVar9;
          android::base::LogMessage::LogMessage
                    ((LogMessage *)&local_60,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x1e8,4
                     ,0,0xffffffff);
          poVar10 = (ostream *)android::base::LogMessage::stream();
          uVar21 = 0x30;
          pcVar17 = "RES_TABLE_PACKAGE_TYPE type ID offset too large.";
          goto LAB_00055ada;
        }
        goto LAB_00055a74;
      }
      *(uint *)pRVar8 = *(uint *)(local_b0 + 0x11c);
    }
    util::ReadUtf16StringFromDevice((ushort *)(local_b0 + 0xc),0x80,psVar1);
    uStack_c4 = *(undefined4 *)((undefined1  [16])0x0 + (undefined1  [16])0x4);
    local_c0 = *(undefined4 **)((undefined1  [16])0x0 + (undefined1  [16])0x8);
    iStack_bc = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
    local_c8 = (void *)0x0;
    local_b8 = 0x3f800000;
    local_4c = 0;
    local_60 = (uchar *)0x0;
    local_50 = 0;
    iVar7 = *(int *)param_1;
    uStack_5c = uStack_c4;
    puStack_58 = local_c0;
    local_54 = iStack_bc;
    ChunkIterator::ChunkIterator
              ((ChunkIterator *)&local_60,iVar7 + (uint)*(ushort *)(iVar7 + 2),
               *(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
               *(int *)(iVar7 + 4) - (uint)*(ushort *)(iVar7 + 2));
    bVar34 = local_50 == 0;
    if ((local_50 == 0) && (local_54 != 0)) {
      ppVar35 = (piecewise_construct_t *)0x0;
      pIVar36 = *(IncFsFileMap **)((undefined1  [16])0x0 + (undefined1  [16])0x4);
      ppVar37 = *(piecewise_construct_t **)((undefined1  [16])0x0 + (undefined1  [16])0x8);
      iVar7 = *(int *)((undefined1  [16])0x0 + (undefined1  [16])0xc);
LAB_0005442c:
      local_d8 = (piecewise_construct_t *)0x0;
      local_d4 = (IncFsFileMap *)0x0;
      local_d0 = (piecewise_construct_t *)0x0;
      ChunkIterator::Next();
      switch(*(short *)local_d8) {
      case 0x201:
        ppVar20 = local_d8;
        pIVar23 = local_d4;
        if (*(ushort *)(local_d8 + 2) < 0x18) {
          ppVar20 = (piecewise_construct_t *)0x0;
          pIVar23 = (IncFsFileMap *)0x0;
        }
        local_88 = CONCAT44(pIVar23,ppVar20);
        local_80 = local_d0;
        if (*(ushort *)(local_d8 + 2) < 0x18) {
          local_80 = (piecewise_construct_t *)0x0;
        }
        if (ppVar20 == (piecewise_construct_t *)0x0) {
LAB_000554b2:
          iVar7 = android::base::ShouldLog(4,0);
          if (iVar7 == 0) goto LAB_00055784;
          puVar9 = (undefined4 *)__errno();
          uVar26 = *puVar9;
          this_03 = (LogMessage *)&local_a0;
          android::base::LogMessage::LogMessage
                    (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x247,4,0,0xffffffff);
          poVar10 = (ostream *)android::base::LogMessage::stream();
          uVar21 = 0x1e;
          pcVar17 = "RES_TABLE_TYPE_TYPE too small.";
        }
        else {
          ppVar25 = local_d8;
          if ((pIVar23 != (IncFsFileMap *)0x0) &&
             ((local_130 = ppVar20 + 0x54, local_a0 = ppVar20, ppVar20 < local_80 ||
              (local_80 + 0x1000 < local_130)))) {
            iVar12 = incfs::IncFsFileMap::Verify
                               (pIVar23,(uchar **)&local_a0,(uchar **)&local_130,(uchar **)&local_80
                               );
            if (iVar12 == 0) goto LAB_000554b2;
            ppVar25 = (piecewise_construct_t *)local_88;
          }
          if (ppVar25[8] == (piecewise_construct_t)0x0) {
            iVar7 = android::base::ShouldLog(4,0);
            if (iVar7 == 0) goto LAB_00055784;
            puVar9 = (undefined4 *)__errno();
            uVar26 = *puVar9;
            this_03 = (LogMessage *)&local_a0;
            android::base::LogMessage::LogMessage
                      (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x4e,4,0,0xffffffff);
            poVar10 = (ostream *)android::base::LogMessage::stream();
            uVar21 = 0x25;
            pcVar17 = "RES_TABLE_TYPE_TYPE has invalid ID 0.";
          }
          else {
            uVar21 = *(uint *)(ppVar25 + 0xc);
            if (0xffff < uVar21) {
              iVar7 = android::base::ShouldLog(4,0);
              if (iVar7 != 0) {
                puVar9 = (undefined4 *)__errno();
                uVar26 = *puVar9;
                android::base::LogMessage::LogMessage
                          ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp",
                           0x54,4,0,0xffffffff);
                poVar10 = (ostream *)android::base::LogMessage::stream();
                poVar10 = std::__put_character_sequence<char,std::char_traits<char>>
                                    (poVar10,"RES_TABLE_TYPE_TYPE has too many entries (",0x2a);
                poVar10 = (ostream *)std::ostream::operator<<(poVar10,uVar21);
                std::__put_character_sequence<char,std::char_traits<char>>(poVar10,").",2);
                android::base::LogMessage::~LogMessage((LogMessage *)&local_a0);
                *puVar9 = uVar26;
              }
              goto LAB_00055784;
            }
            uVar11 = *(uint *)(ppVar25 + 0x10);
            if (*(ushort *)(ppVar25 + 2) <= uVar11) {
              iVar12 = 1;
              if (-1 < (int)((uint)(byte)ppVar25[9] << 0x1e)) {
                iVar12 = 2;
              }
              if (uVar21 << iVar12 <= uVar11 - *(ushort *)(ppVar25 + 2)) {
                if (*(uint *)(ppVar25 + 4) < uVar11) {
                  iVar7 = android::base::ShouldLog(4,0);
                  if (iVar7 != 0) {
                    puVar9 = (undefined4 *)__errno();
                    uVar26 = *puVar9;
                    this_03 = (LogMessage *)&local_a0;
                    android::base::LogMessage::LogMessage
                              (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x65,4,0,
                               0xffffffff);
                    poVar10 = (ostream *)android::base::LogMessage::stream();
                    uVar21 = 0x36;
                    pcVar17 = "RES_TABLE_TYPE_TYPE entry offsets extend beyond chunk.";
                    break;
                  }
                  goto LAB_00055784;
                }
                if ((uVar11 & 3) == 0) {
                  local_a0 = (piecewise_construct_t *)(uint)(byte)ppVar25[8];
                  piVar31 = (int *)std::
                                   unordered_map<int,std::unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const,std::unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>>>>
                                   ::operator[]((unordered_map<int,std::unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const,std::unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>>>>
                                                 *)&local_c8,(int *)&local_a0);
                  ppVar20 = local_80;
                  iVar12 = *piVar31;
                  if (iVar12 != 0) {
                    puVar9 = *(undefined4 **)(iVar12 + 0x10);
                    puVar6 = (uchar *)(piecewise_construct_t *)local_88;
                    uVar26 = local_88._4_4_;
                    if (puVar9 < *(undefined4 **)(iVar12 + 0x14)) {
                      *puVar9 = ppVar35;
                      puVar9[1] = pIVar36;
                      puVar9[2] = ppVar37;
                      puVar9[3] = iVar7;
                      puVar9[4] = ppVar35;
                      puVar9[5] = pIVar36;
                      puVar9[6] = ppVar37;
                      puVar9[7] = iVar7;
                      puVar9[8] = ppVar35;
                      puVar9[9] = pIVar36;
                      puVar9[10] = ppVar37;
                      puVar9[0xb] = iVar7;
                      puVar9[0xc] = ppVar35;
                      puVar9[0xd] = pIVar36;
                      puVar9[0xe] = ppVar37;
                      puVar9[0xf] = iVar7;
                      puVar9[0xf] = ppVar35;
                      puVar9[0x10] = pIVar36;
                      puVar9[0x11] = ppVar37;
                      puVar9[0x12] = iVar7;
                      iVar29 = *(int *)(iVar12 + 0x10) + 0x4c;
                      *(int *)(iVar12 + 0x10) = iVar29;
                    }
                    else {
                      std::
                      vector<android::TypeSpec::TypeEntry,std::allocator<android::TypeSpec::TypeEntry>>
                      ::__emplace_back_slow_path<>
                                ((vector<android::TypeSpec::TypeEntry,std::allocator<android::TypeSpec::TypeEntry>>
                                  *)(iVar12 + 0xc));
                      iVar29 = *(int *)(iVar12 + 0x10);
                    }
                    ResTable_config::copyFromDtoH
                              ((ResTable_config *)(iVar29 + -0x40),
                               (ResTable_config *)(puVar6 + 0x14));
                    *(uchar **)(iVar29 + -0x4c) = puVar6;
                    *(undefined4 *)(iVar29 + -0x48) = uVar26;
                    *(piecewise_construct_t **)(iVar29 + -0x44) = ppVar20;
                    goto LAB_0005506a;
                  }
                  iVar7 = android::base::ShouldLog(4,0);
                  if (iVar7 != 0) {
                    puVar9 = (undefined4 *)__errno();
                    uVar26 = *puVar9;
                    android::base::LogMessage::LogMessage
                              ((LogMessage *)&local_130,
                               "frameworks/base/libs/androidfw/LoadedArsc.cpp",0x254,4,0,0xffffffff)
                    ;
                    poVar10 = (ostream *)android::base::LogMessage::stream();
                    android::base::StringPrintf
                              ((char *)&local_a0,
                               "RES_TABLE_TYPE_TYPE with ID %02x found without preceding RES_TABLE_TYPE_SPEC_TYPE."
                               ,(uint)*(byte *)((piecewise_construct_t *)local_88 + 8));
                    std::operator<<(poVar10,(string *)&local_a0);
                    if (((uint)local_a0 & 1) != 0) {
                      operator_delete(local_98);
                    }
                    android::base::LogMessage::~LogMessage((LogMessage *)&local_130);
                    *puVar9 = uVar26;
                  }
                  goto LAB_00055784;
                }
                iVar7 = android::base::ShouldLog(4,0);
                if (iVar7 == 0) goto LAB_00055784;
                puVar9 = (undefined4 *)__errno();
                uVar26 = *puVar9;
                this_03 = (LogMessage *)&local_a0;
                android::base::LogMessage::LogMessage
                          (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x6a,4,0,
                           0xffffffff);
                poVar10 = (ostream *)android::base::LogMessage::stream();
                uVar21 = 0x37;
                pcVar17 = "RES_TABLE_TYPE_TYPE entries start at unaligned address.";
                break;
              }
            }
            iVar7 = android::base::ShouldLog(4,0);
            if (iVar7 == 0) goto LAB_00055784;
            puVar9 = (undefined4 *)__errno();
            uVar26 = *puVar9;
            this_03 = (LogMessage *)&local_a0;
            android::base::LogMessage::LogMessage
                      (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x60,4,0,0xffffffff);
            poVar10 = (ostream *)android::base::LogMessage::stream();
            uVar21 = 0x3c;
            pcVar17 = "RES_TABLE_TYPE_TYPE entry offsets overlap actual entry data.";
          }
        }
        break;
      case 0x202:
        ppVar20 = local_d8;
        pIVar23 = local_d4;
        if (*(ushort *)(local_d8 + 2) < 0x10) {
          ppVar20 = (piecewise_construct_t *)0x0;
          pIVar23 = (IncFsFileMap *)0x0;
        }
        local_88 = CONCAT44(pIVar23,ppVar20);
        local_80 = local_d0;
        if (*(ushort *)(local_d8 + 2) < 0x10) {
          local_80 = (piecewise_construct_t *)0x0;
        }
        if (ppVar20 == (piecewise_construct_t *)0x0) {
LAB_000554f0:
          iVar7 = android::base::ShouldLog(4,0);
          if (iVar7 == 0) goto LAB_00055784;
          puVar9 = (undefined4 *)__errno();
          uVar26 = *puVar9;
          android::base::LogMessage::LogMessage
                    ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x21a,4
                     ,0,0xffffffff);
          poVar10 = (ostream *)android::base::LogMessage::stream();
          uVar21 = 0x23;
          pcVar17 = "RES_TABLE_TYPE_SPEC_TYPE too small.";
        }
        else {
          ppVar25 = local_d8;
          if ((pIVar23 != (IncFsFileMap *)0x0) &&
             ((local_130 = ppVar20 + 0x10, local_a0 = ppVar20, ppVar20 < local_80 ||
              (local_80 + 0x1000 < local_130)))) {
            iVar12 = incfs::IncFsFileMap::Verify
                               (pIVar23,(uchar **)&local_a0,(uchar **)&local_130,(uchar **)&local_80
                               );
            if (iVar12 == 0) goto LAB_000554f0;
            ppVar25 = (piecewise_construct_t *)local_88;
          }
          ppVar20 = (piecewise_construct_t *)(uint)(byte)ppVar25[8];
          if (ppVar20 == (piecewise_construct_t *)0x0) {
            iVar7 = android::base::ShouldLog(4,0);
            if (iVar7 == 0) goto LAB_00055784;
            puVar9 = (undefined4 *)__errno();
            uVar26 = *puVar9;
            android::base::LogMessage::LogMessage
                      ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x21f
                       ,4,0,0xffffffff);
            poVar10 = (ostream *)android::base::LogMessage::stream();
            uVar21 = 0x2a;
            pcVar17 = "RES_TABLE_TYPE_SPEC_TYPE has invalid ID 0.";
          }
          else if ((int)(ppVar20 + *(int *)pRVar8) < 0x100) {
            uVar21 = *(uint *)(ppVar25 + 0xc);
            if (uVar21 < 0x10000) {
              if (uVar21 << 2 <=
                  *(int *)(*(int *)param_1 + 4) - (uint)*(ushort *)(*(int *)param_1 + 2)) {
                local_a0 = ppVar20;
                this_02 = (unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>
                           *)std::
                             unordered_map<int,std::unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const,std::unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>>>>
                             ::operator[]((unordered_map<int,std::unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>,std::hash<int>,std::equal_to<int>,std::allocator<std::pair<int_const,std::unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>>>>
                                           *)&local_c8,(int *)&local_a0);
                ppVar20 = local_80;
                if (*(int *)this_02 == 0) {
                  puVar6 = (uchar *)(piecewise_construct_t *)local_88;
                  uVar26 = local_88._4_4_;
                  local_a0 = operator_new(0x18);
                  *(uchar **)local_a0 = puVar6;
                  *(undefined4 *)(local_a0 + 0x10) = 0;
                  *(undefined4 *)(local_a0 + 0x14) = 0;
                  *(undefined4 *)(local_a0 + 4) = uVar26;
                  *(piecewise_construct_t **)(local_a0 + 8) = ppVar20;
                  *(undefined4 *)(local_a0 + 0xc) = 0;
                  std::
                  unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>
                  ::operator=(this_02,(unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>
                                       *)&local_a0);
                  std::
                  unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>
                  ::reset((unique_ptr<android::(anonymous_namespace)::TypeSpecBuilder,std::default_delete<android::(anonymous_namespace)::TypeSpecBuilder>>
                           *)&local_a0,(TypeSpecBuilder *)0x0);
                  puVar13 = (uint *)ByteBucketArray<unsigned_int>::editItemAt
                                              ((ByteBucketArray<unsigned_int> *)(this_00 + 0xe8),
                                               (uint)*(byte *)((piecewise_construct_t *)local_88 + 8
                                                              ));
                  *puVar13 = uVar21;
                }
                else {
                  iVar12 = android::base::ShouldLog(3,0);
                  if (iVar12 != 0) {
                    puVar9 = (undefined4 *)__errno();
                    uVar26 = *puVar9;
                    android::base::LogMessage::LogMessage
                              ((LogMessage *)&local_130,
                               "frameworks/base/libs/androidfw/LoadedArsc.cpp",0x23f,3,0,0xffffffff)
                    ;
                    poVar10 = (ostream *)android::base::LogMessage::stream();
                    android::base::StringPrintf
                              ((char *)&local_a0,
                               "RES_TABLE_TYPE_SPEC_TYPE already defined for ID %02x",
                               (uint)*(byte *)((piecewise_construct_t *)local_88 + 8));
                    std::operator<<(poVar10,(string *)&local_a0);
                    if (((uint)local_a0 & 1) != 0) {
                      operator_delete(local_98);
                    }
                    android::base::LogMessage::~LogMessage((LogMessage *)&local_130);
                    *puVar9 = uVar26;
                  }
                }
                goto LAB_0005506a;
              }
              iVar7 = android::base::ShouldLog(4,0);
              if (iVar7 == 0) goto LAB_00055784;
              puVar9 = (undefined4 *)__errno();
              uVar26 = *puVar9;
              android::base::LogMessage::LogMessage
                        ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp",
                         0x236,4,0,0xffffffff);
              poVar10 = (ostream *)android::base::LogMessage::stream();
              uVar21 = 0x33;
              pcVar17 = "RES_TABLE_TYPE_SPEC_TYPE too small to hold entries.";
            }
            else {
              iVar7 = android::base::ShouldLog(4,0);
              if (iVar7 == 0) goto LAB_00055784;
              puVar9 = (undefined4 *)__errno();
              uVar26 = *puVar9;
              android::base::LogMessage::LogMessage
                        ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp",
                         0x231,4,0,0xffffffff);
              poVar10 = (ostream *)android::base::LogMessage::stream();
              poVar10 = std::__put_character_sequence<char,std::char_traits<char>>
                                  (poVar10,"RES_TABLE_TYPE_SPEC_TYPE has too many entries (",0x2f);
              poVar10 = (ostream *)std::ostream::operator<<(poVar10,uVar21);
              uVar21 = 2;
              pcVar17 = ").";
            }
          }
          else {
            iVar7 = android::base::ShouldLog(4,0);
            if (iVar7 == 0) goto LAB_00055784;
            puVar9 = (undefined4 *)__errno();
            uVar26 = *puVar9;
            android::base::LogMessage::LogMessage
                      ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x225
                       ,4,0,0xffffffff);
            poVar10 = (ostream *)android::base::LogMessage::stream();
            uVar21 = 0x2d;
            pcVar17 = "RES_TABLE_TYPE_SPEC_TYPE has out of range ID.";
          }
        }
        std::__put_character_sequence<char,std::char_traits<char>>(poVar10,pcVar17,uVar21);
        android::base::LogMessage::~LogMessage((LogMessage *)&local_a0);
        *puVar9 = uVar26;
        goto LAB_00055784;
      case 0x203:
        ppVar20 = local_d8;
        pIVar23 = local_d4;
        if (*(ushort *)(local_d8 + 2) < 0xc) {
          ppVar20 = (piecewise_construct_t *)0x0;
          pIVar23 = (IncFsFileMap *)0x0;
        }
        local_88 = CONCAT44(pIVar23,ppVar20);
        local_80 = local_d0;
        if (*(ushort *)(local_d8 + 2) < 0xc) {
          local_80 = (piecewise_construct_t *)0x0;
        }
        if (ppVar20 == (piecewise_construct_t *)0x0) {
LAB_0005552e:
          iVar7 = android::base::ShouldLog(4,0);
          if (iVar7 == 0) goto LAB_00055784;
          puVar9 = (undefined4 *)__errno();
          uVar26 = *puVar9;
          this_03 = (LogMessage *)&local_a0;
          android::base::LogMessage::LogMessage
                    (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x25e,4,0,0xffffffff);
          poVar10 = (ostream *)android::base::LogMessage::stream();
          uVar21 = 0x21;
          pcVar17 = "RES_TABLE_LIBRARY_TYPE too small.";
        }
        else {
          ppVar25 = local_d8;
          if ((pIVar23 != (IncFsFileMap *)0x0) &&
             ((local_130 = ppVar20 + 0xc, local_a0 = ppVar20, ppVar20 < local_80 ||
              (local_80 + 0x1000 < local_130)))) {
            iVar12 = incfs::IncFsFileMap::Verify
                               (pIVar23,(uchar **)&local_a0,(uchar **)&local_130,(uchar **)&local_80
                               );
            if (iVar12 == 0) goto LAB_0005552e;
            ppVar25 = (piecewise_construct_t *)local_88;
          }
          if (*(uint *)(ppVar25 + 8) <=
              (*(int *)(local_d8 + 4) - (uint)*(ushort *)(local_d8 + 2)) / 0x104) {
            std::vector<android::DynamicPackageEntry,std::allocator<android::DynamicPackageEntry>>::
            reserve(this_01,*(uint *)(ppVar25 + 8));
            pIStack_9c = local_d4;
            local_98 = local_d0;
            local_a0 = local_d8 + *(ushort *)(local_d8 + 2);
            if (*(int *)((piecewise_construct_t *)local_88 + 8) != 0) {
              ppVar25 = local_a0 + *(int *)((piecewise_construct_t *)local_88 + 8) * 0x104;
              ppVar20 = local_a0;
              do {
                local_130 = ppVar20;
                local_a0 = local_130;
                if (pIStack_9c != (IncFsFileMap *)0x0) {
                  local_70 = local_130 + 0x104;
                  if (((local_130 < local_98) || (local_98 + 0x1000 < local_70)) &&
                     (iVar12 = incfs::IncFsFileMap::Verify
                                         (pIStack_9c,(uchar **)&local_130,(uchar **)&local_70,
                                          (uchar **)&local_98), iVar12 == 0)) {
                    *(undefined4 *)this = 0;
                    pvVar16 = local_c8;
                    puVar9 = local_c0;
                    goto joined_r0x0005578c;
                  }
                }
                local_130 = (piecewise_construct_t *)0x0;
                pIStack_12c = (IncFsFileMap *)0x0;
                local_128 = (piecewise_construct_t *)0x0;
                util::ReadUtf16StringFromDevice((ushort *)(local_a0 + 4),0x80,(string *)&local_130);
                uVar21 = *(uint *)local_a0;
                if (uVar21 < 0xff) {
                  puVar9 = *(undefined4 **)(this_00 + 300);
                  if (puVar9 < *(undefined4 **)(this_00 + 0x130)) {
                    puVar9[3] = uVar21;
                    puVar9[2] = local_128;
                    *puVar9 = local_130;
                    puVar9[1] = pIStack_12c;
                    local_130 = (piecewise_construct_t *)0x0;
                    pIStack_12c = (IncFsFileMap *)0x0;
                    local_128 = (piecewise_construct_t *)0x0;
                    *(int *)(this_00 + 300) = *(int *)(this_00 + 300) + 0x10;
                  }
                  else {
                    std::
                    vector<android::DynamicPackageEntry,std::allocator<android::DynamicPackageEntry>>
                    ::__emplace_back_slow_path<std::string,unsigned_int_const&>
                              (this_01,(string *)&local_130,(uint *)local_a0);
                  }
                }
                else {
                  iVar12 = android::base::ShouldLog(4,0);
                  if (iVar12 != 0) {
                    puVar9 = (undefined4 *)__errno();
                    uVar26 = *puVar9;
                    android::base::LogMessage::LogMessage
                              ((LogMessage *)&local_e8,
                               "frameworks/base/libs/androidfw/LoadedArsc.cpp",0x275,4,0,0xffffffff)
                    ;
                    poVar10 = (ostream *)android::base::LogMessage::stream();
                    ppVar20 = local_128;
                    if (((uint)local_130 & 1) == 0) {
                      ppVar20 = (piecewise_construct_t *)((int)&local_130 + 1);
                    }
                    android::base::StringPrintf
                              ((char *)&local_70,
                               "Package ID %02x in RES_TABLE_LIBRARY_TYPE too large for package \'%s\'."
                               ,*(undefined4 *)local_a0,ppVar20);
                    std::operator<<(poVar10,(string *)&local_70);
                    if (((uint)local_70 & 1) != 0) {
                      operator_delete(local_68[0]);
                    }
                    android::base::LogMessage::~LogMessage((LogMessage *)&local_e8);
                    *puVar9 = uVar26;
                  }
                  *(undefined4 *)this = 0;
                }
                if (((uint)local_130 & 1) != 0) {
                  operator_delete(local_128);
                }
                pvVar16 = local_c8;
                puVar9 = local_c0;
                if (0xfe < uVar21) goto joined_r0x0005578c;
                local_a0 = local_a0 + 0x104;
                ppVar20 = local_a0;
              } while (local_a0 != ppVar25);
            }
            goto LAB_0005506a;
          }
          iVar7 = android::base::ShouldLog(4,0);
          if (iVar7 == 0) goto LAB_00055784;
          puVar9 = (undefined4 *)__errno();
          uVar26 = *puVar9;
          this_03 = (LogMessage *)&local_a0;
          android::base::LogMessage::LogMessage
                    (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x263,4,0,0xffffffff);
          poVar10 = (ostream *)android::base::LogMessage::stream();
          uVar21 = 0x31;
          pcVar17 = "RES_TABLE_LIBRARY_TYPE too small to hold entries.";
        }
        break;
      case 0x204:
        local_68[0] = local_d0;
        local_70 = local_d8;
        local_6c = local_d4;
        if (*(ushort *)(local_d8 + 2) >> 3 < 0x81) {
          local_6c = (IncFsFileMap *)0x0;
          local_68[0] = (piecewise_construct_t *)0x0;
          local_70 = (piecewise_construct_t *)0x0;
        }
        if (local_70 == (piecewise_construct_t *)0x0) {
LAB_0005556c:
          iVar7 = android::base::ShouldLog(4,0);
          if (iVar7 != 0) {
            puVar9 = (undefined4 *)__errno();
            uVar26 = *puVar9;
            android::base::LogMessage::LogMessage
                      ((LogMessage *)&local_88,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x283
                       ,4,0,0xffffffff);
            poVar10 = (ostream *)android::base::LogMessage::stream();
            std::__put_character_sequence<char,std::char_traits<char>>
                      (poVar10,"RES_TABLE_OVERLAYABLE_TYPE too small.",0x25);
            android::base::LogMessage::~LogMessage((LogMessage *)&local_88);
            *puVar9 = uVar26;
          }
          *(undefined4 *)this = 0;
          pvVar16 = local_c8;
          puVar9 = local_c0;
        }
        else {
          ppVar20 = local_d8;
          if (local_6c != (IncFsFileMap *)0x0) {
            local_a0 = local_70 + 0x408;
            local_88 = CONCAT44(local_88._4_4_,local_70);
            if (((local_70 < local_68[0]) || (local_68[0] + 0x1000 < local_a0)) &&
               (iVar12 = incfs::IncFsFileMap::Verify
                                   (local_6c,(uchar **)&local_88,(uchar **)&local_a0,
                                    (uchar **)local_68), ppVar20 = local_70, iVar12 == 0))
            goto LAB_0005556c;
          }
          local_e8 = (piecewise_construct_t *)0x0;
          uStack_e4 = 0;
          local_e0 = (void *)0x0;
          util::ReadUtf16StringFromDevice((ushort *)(ppVar20 + 8),0x100,(string *)&local_e8);
          local_f8 = 0;
          uStack_f4 = 0;
          local_f0 = (void *)0x0;
          util::ReadUtf16StringFromDevice((ushort *)(local_70 + 0x208),0x100,(string *)&local_f8);
          std::
          __hash_table<std::__hash_value_type<std::string,std::string>,std::__unordered_map_hasher<std::string,std::__hash_value_type<std::string,std::string>,std::hash<std::string>,true>,std::__unordered_map_equal<std::string,std::__hash_value_type<std::string,std::string>,std::equal_to<std::string>,true>,std::allocator<std::__hash_value_type<std::string,std::string>>>
          ::__emplace_unique_key_args<std::string,std::string,std::string>
                    ((string *)&local_88,(string *)(this_00 + 0x14c),(string *)&local_e8);
          puVar6 = (uchar *)(piecewise_construct_t *)local_88;
          if (local_88._4_1_ == '\0') {
            iVar12 = android::base::ShouldLog(4,0);
            if (iVar12 != 0) {
              puVar9 = (undefined4 *)__errno();
              uVar26 = *puVar9;
              android::base::LogMessage::LogMessage
                        ((LogMessage *)&local_88,"frameworks/base/libs/androidfw/LoadedArsc.cpp",
                         0x28e,4,0,0xffffffff);
              poVar10 = (ostream *)android::base::LogMessage::stream();
              poVar10 = std::__put_character_sequence<char,std::char_traits<char>>
                                  (poVar10,"Multiple <overlayable> blocks with the same name \'",
                                   0x32);
              poVar10 = std::operator<<(poVar10,(string *)(puVar6 + 8));
              std::__put_character_sequence<char,std::char_traits<char>>(poVar10,"\'.",2);
              android::base::LogMessage::~LogMessage((LogMessage *)&local_88);
              *puVar9 = uVar26;
            }
            cVar28 = '\x01';
            *(undefined4 *)this = 0;
          }
          else {
            local_74 = 0;
            local_88 = CONCAT44(pIVar36,ppVar35);
            local_78 = 0;
            local_80 = ppVar37;
            local_7c = iVar7;
            ChunkIterator::ChunkIterator
                      ((ChunkIterator *)&local_88,local_d8 + *(ushort *)(local_d8 + 2),local_d4,
                       local_d0,*(int *)(local_d8 + 4) - (uint)*(ushort *)(local_d8 + 2));
            do {
              while( true ) {
                if ((local_78 != 0) || (local_7c == 0)) {
                  if (local_78 == 0) {
                    cVar28 = '\0';
                  }
                  else {
                    iVar12 = android::base::ShouldLog(4,0);
                    if (iVar12 != 0) {
                      puVar9 = (undefined4 *)__errno();
                      uVar26 = *puVar9;
                      android::base::LogMessage::LogMessage
                                ((LogMessage *)&local_108,
                                 "frameworks/base/libs/androidfw/LoadedArsc.cpp",0x2c5,4,0,
                                 0xffffffff);
                      poVar10 = (ostream *)android::base::LogMessage::stream();
                      ChunkIterator::GetLastError();
                      ppVar20 = local_128;
                      if (((uint)local_130 & 1) == 0) {
                        ppVar20 = (piecewise_construct_t *)((int)&local_130 + 1);
                      }
                      android::base::StringPrintf
                                ((char *)&local_a0,"Error parsing RES_TABLE_OVERLAYABLE_TYPE: %s",
                                 ppVar20);
                      std::operator<<(poVar10,(string *)&local_a0);
                      if (((uint)local_a0 & 1) != 0) {
                        operator_delete(local_98);
                      }
                      if (((uint)local_130 & 1) != 0) {
                        operator_delete(local_128);
                      }
                      android::base::LogMessage::~LogMessage((LogMessage *)&local_108);
                      *puVar9 = uVar26;
                    }
                    bVar34 = local_78 != 0;
                    uVar21 = 0;
                    if (bVar34) {
                      uVar21 = local_74 & 0xff;
                    }
                    if (bVar34 && uVar21 != 0) {
                      *(undefined4 *)this = 0;
                    }
                    cVar28 = bVar34 && uVar21 != 0;
                  }
                  goto LAB_00055048;
                }
                local_108 = (piecewise_construct_t *)0x0;
                local_104 = (IncFsFileMap *)0x0;
                local_100 = (piecewise_construct_t *)0x0;
                ChunkIterator::Next();
                if (*(short *)local_108 == 0x205) break;
                iVar12 = android::base::ShouldLog(3,0);
                if (iVar12 != 0) {
                  puVar9 = (undefined4 *)__errno();
                  uVar26 = *puVar9;
                  android::base::LogMessage::LogMessage
                            ((LogMessage *)&local_130,
                             "frameworks/base/libs/androidfw/LoadedArsc.cpp",0x2bf,3,0,0xffffffff);
                  poVar10 = (ostream *)android::base::LogMessage::stream();
                  android::base::StringPrintf
                            ((char *)&local_a0,"Unknown chunk type \'%02x\'.",
                             (uint)**(ushort **)param_1);
                  std::operator<<(poVar10,(string *)&local_a0);
                  if (((uint)local_a0 & 1) != 0) {
                    operator_delete(local_98);
                  }
                  android::base::LogMessage::~LogMessage((LogMessage *)&local_130);
                  *puVar9 = uVar26;
                }
              }
              local_110[0] = local_100;
              local_118 = local_108;
              local_114 = local_104;
              if (*(ushort *)(local_108 + 2) < 0x10) {
                local_114 = (IncFsFileMap *)0x0;
                local_110[0] = (piecewise_construct_t *)0x0;
                local_118 = (piecewise_construct_t *)0x0;
              }
              if ((local_118 == (piecewise_construct_t *)0x0) ||
                 ((ppVar20 = local_108, local_114 != (IncFsFileMap *)0x0 &&
                  (((local_130 = local_118 + 0x10, local_a0 = local_118, local_118 < local_110[0] ||
                    (local_110[0] + 0x1000 < local_130)) &&
                   (iVar12 = incfs::IncFsFileMap::Verify
                                       (local_114,(uchar **)&local_a0,(uchar **)&local_130,
                                        (uchar **)local_110), ppVar20 = local_118, iVar12 == 0))))))
              {
                iVar12 = android::base::ShouldLog(4,0);
                if (iVar12 != 0) {
                  puVar9 = (undefined4 *)__errno();
                  uVar26 = *puVar9;
                  android::base::LogMessage::LogMessage
                            ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp"
                             ,0x29d,4,0,0xffffffff);
                  poVar10 = (ostream *)android::base::LogMessage::stream();
                  uVar21 = 0x2c;
                  pcVar17 = "RES_TABLE_OVERLAYABLE_POLICY_TYPE too small.";
LAB_000553a0:
                  std::__put_character_sequence<char,std::char_traits<char>>(poVar10,pcVar17,uVar21)
                  ;
                  android::base::LogMessage::~LogMessage((LogMessage *)&local_a0);
                  *puVar9 = uVar26;
                }
LAB_00055038:
                cVar28 = '\x01';
                *(undefined4 *)this = 0;
                break;
              }
              ppVar27 = local_100;
              pIVar23 = local_104;
              ppVar25 = local_108;
              uVar3 = *(ushort *)(local_108 + 2);
              uVar21 = *(uint *)(ppVar20 + 0xc);
              if (*(int *)(local_108 + 4) - (uint)uVar3 >> 2 < uVar21) {
                iVar12 = android::base::ShouldLog(4,0);
                if (iVar12 != 0) {
                  puVar9 = (undefined4 *)__errno();
                  uVar26 = *puVar9;
                  android::base::LogMessage::LogMessage
                            ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp"
                             ,0x2a2,4,0,0xffffffff);
                  poVar10 = (ostream *)android::base::LogMessage::stream();
                  uVar21 = 0x3c;
                  pcVar17 = "RES_TABLE_OVERLAYABLE_POLICY_TYPE too small to hold entries.";
                  goto LAB_000553a0;
                }
                goto LAB_00055038;
              }
              local_90 = 0x3f800000;
              local_a0 = ppVar35;
              pIStack_9c = pIVar36;
              local_98 = ppVar37;
              iStack_94 = iVar7;
              std::
              __hash_table<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>
              ::reserve((__hash_table<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>
                         *)&local_a0,uVar21);
              pIStack_12c = pIVar23;
              local_128 = ppVar27;
              local_130 = ppVar25 + uVar3;
              if (uVar21 != 0) {
                ppVar20 = local_130 + uVar21 * 4;
                do {
                  if ((local_130 == (piecewise_construct_t *)0x0) ||
                     (((pIStack_12c != (IncFsFileMap *)0x0 &&
                       ((local_a4 = local_130 + 4, local_44[0] = local_130, local_130 < local_128 ||
                        (local_128 + 0x1000 < local_a4)))) &&
                      (iVar12 = incfs::IncFsFileMap::Verify
                                          (pIStack_12c,(uchar **)local_44,(uchar **)&local_a4,
                                           (uchar **)&local_128), iVar12 == 0)))) {
                    iVar12 = android::base::ShouldLog(4,0);
                    if (iVar12 != 0) {
                      puVar9 = (undefined4 *)__errno();
                      uVar26 = *puVar9;
                      android::base::LogMessage::LogMessage
                                ((LogMessage *)local_44,
                                 "frameworks/base/libs/androidfw/LoadedArsc.cpp",0x2ad,4,0,
                                 0xffffffff);
                      poVar10 = (ostream *)android::base::LogMessage::stream();
                      std::__put_character_sequence<char,std::char_traits<char>>
                                (poVar10,"NULL ResTable_ref record??",0x1a);
                      android::base::LogMessage::~LogMessage((LogMessage *)local_44);
                      *puVar9 = uVar26;
                    }
                    bVar34 = false;
                    cVar28 = '\x01';
                    *(undefined4 *)this = 0;
                    ppVar20 = local_a0;
                    ppVar25 = local_98;
                    goto joined_r0x00054bac;
                  }
                  std::
                  __hash_table<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>
                  ::__emplace_unique_key_args<unsigned_int,unsigned_int_const&>
                            ((uint *)local_44,(uint *)&local_a0);
                  local_130 = local_130 + 4;
                } while (local_130 != ppVar20);
              }
              pIVar23 = pIStack_9c;
              ppVar20 = local_a0;
              bVar2 = puVar6[0x14];
              local_124 = *(uint *)(puVar6 + 0x18);
              local_128 = *(piecewise_construct_t **)(puVar6 + 0x1c);
              if ((bVar2 & 1) == 0) {
                local_124 = (uint)(bVar2 >> 1);
              }
              pIStack_12c = *(IncFsFileMap **)(puVar6 + 0xc);
              if ((bVar2 & 1) == 0) {
                local_128 = (piecewise_construct_t *)(puVar6 + 0x15);
              }
              local_130 = *(piecewise_construct_t **)(puVar6 + 0x10);
              local_120 = *(undefined4 *)(local_118 + 8);
              if ((puVar6[8] & 1) == 0) {
                pIStack_12c = (IncFsFileMap *)(uint)(puVar6[8] >> 1);
                local_130 = (piecewise_construct_t *)(puVar6 + 9);
              }
              puVar9 = *(undefined4 **)(this_00 + 0x138);
              if (puVar9 < *(undefined4 **)(this_00 + 0x13c)) {
                *puVar9 = local_130;
                puVar9[1] = pIStack_12c;
                puVar9[2] = local_128;
                puVar9[3] = local_124;
                puVar9[4] = local_120;
                puVar9[7] = local_98;
                local_a0 = (piecewise_construct_t *)0x0;
                pIStack_9c = (IncFsFileMap *)0x0;
                puVar9[5] = ppVar20;
                puVar9[6] = pIVar23;
                puVar9[8] = iStack_94;
                puVar9[9] = local_90;
                if (iStack_94 != 0) {
                  pIVar24 = *(IncFsFileMap **)(local_98 + 4);
                  if (((uint)pIVar23 & (uint)(pIVar23 + -1)) == 0) {
                    pIVar24 = (IncFsFileMap *)((uint)pIVar24 & (uint)(pIVar23 + -1));
                  }
                  else if (pIVar23 <= pIVar24) {
                    pIVar24 = pIVar24 + -(((uint)pIVar24 / (uint)pIVar23) * (int)pIVar23);
                  }
                  *(undefined4 **)(ppVar20 + (int)pIVar24 * 4) = puVar9 + 7;
                  local_98 = (piecewise_construct_t *)0x0;
                  iStack_94 = 0;
                }
                *(int *)(this_00 + 0x138) = *(int *)(this_00 + 0x138) + 0x28;
              }
              else {
                std::
                vector<std::pair<android::OverlayableInfo,std::unordered_set<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>>,std::allocator<std::pair<android::OverlayableInfo,std::unordered_set<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>>>>
                ::
                __emplace_back_slow_path<android::OverlayableInfo,std::unordered_set<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>>
                          ((vector<std::pair<android::OverlayableInfo,std::unordered_set<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>>,std::allocator<std::pair<android::OverlayableInfo,std::unordered_set<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>>>>
                            *)(this_00 + 0x134),(OverlayableInfo *)&local_130,
                           (unordered_set *)&local_a0);
              }
              bVar34 = true;
              cVar28 = '\n';
              this_00[0xc4] = (ResStringPool)0x1;
              ppVar20 = local_a0;
              ppVar25 = local_98;
joined_r0x00054bac:
              while (ppVar25 != (piecewise_construct_t *)0x0) {
                ppVar27 = *(piecewise_construct_t **)ppVar25;
                local_a0 = ppVar20;
                operator_delete(ppVar25);
                ppVar20 = local_a0;
                ppVar25 = ppVar27;
              }
              local_a0 = (piecewise_construct_t *)0x0;
              if (ppVar20 != (piecewise_construct_t *)0x0) {
                operator_delete(ppVar20);
              }
            } while (bVar34);
          }
LAB_00055048:
          if ((local_f8 & 1) != 0) {
            operator_delete(local_f0);
          }
          if (((uint)local_e8 & 1) != 0) {
            operator_delete(local_e0);
          }
          pvVar16 = local_c8;
          puVar9 = local_c0;
          if (cVar28 == '\0') goto LAB_0005506a;
        }
        goto joined_r0x0005578c;
      case 0x205:
switchD_00054448_caseD_205:
        iVar12 = android::base::ShouldLog(3,0);
        if (iVar12 != 0) {
          puVar9 = (undefined4 *)__errno();
          uVar26 = *puVar9;
          android::base::LogMessage::LogMessage
                    ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x301,3
                     ,0,0xffffffff);
          poVar10 = (ostream *)android::base::LogMessage::stream();
          android::base::StringPrintf
                    ((char *)&local_88,"Unknown chunk type \'%02x\'.",(uint)**(ushort **)param_1);
          std::operator<<(poVar10,(string *)&local_88);
          if ((local_88 & 1) != 0) {
            operator_delete(local_80);
          }
          android::base::LogMessage::~LogMessage((LogMessage *)&local_a0);
          *puVar9 = uVar26;
        }
        goto LAB_0005506a;
      case 0x206:
        if (*(int *)(this_00 + 200) != 1) {
          iVar12 = android::base::ShouldLog(3,0);
          if (iVar12 != 0) {
            puVar9 = (undefined4 *)__errno();
            uVar26 = *puVar9;
            android::base::LogMessage::LogMessage
                      ((LogMessage *)&local_88,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x2cf
                       ,3,0,0xffffffff);
            poVar10 = (ostream *)android::base::LogMessage::stream();
            poVar10 = std::__put_character_sequence<char,std::char_traits<char>>
                                (poVar10,"Alias chunk ignored for non-framework package \'",0x2f);
            poVar10 = std::operator<<(poVar10,psVar1);
            std::__put_character_sequence<char,std::char_traits<char>>(poVar10,"\'",1);
            android::base::LogMessage::~LogMessage((LogMessage *)&local_88);
            *puVar9 = uVar26;
          }
          goto LAB_0005506a;
        }
        local_98 = local_d0;
        local_a0 = local_d8;
        pIStack_9c = local_d4;
        if (*(ushort *)(local_d8 + 2) < 0xc) {
          pIStack_9c = (IncFsFileMap *)0x0;
          local_98 = (piecewise_construct_t *)0x0;
          local_a0 = (piecewise_construct_t *)0x0;
        }
        if (local_a0 == (piecewise_construct_t *)0x0) {
LAB_000558f0:
          iVar7 = android::base::ShouldLog(4,0);
          if (iVar7 == 0) goto LAB_00055784;
          puVar9 = (undefined4 *)__errno();
          uVar26 = *puVar9;
          this_03 = (LogMessage *)&local_88;
          android::base::LogMessage::LogMessage
                    (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x2d6,4,0,0xffffffff);
          poVar10 = (ostream *)android::base::LogMessage::stream();
          uVar21 = 0x29;
          pcVar17 = "RES_TABLE_STAGED_ALIAS_TYPE is too small.";
        }
        else {
          ppVar20 = local_d8;
          if (pIStack_9c != (IncFsFileMap *)0x0) {
            local_130 = local_a0 + 0xc;
            local_88 = CONCAT44(local_88._4_4_,local_a0);
            if (((local_a0 < local_98) || (local_98 + 0x1000 < local_130)) &&
               (iVar12 = incfs::IncFsFileMap::Verify
                                   (pIStack_9c,(uchar **)&local_88,(uchar **)&local_130,
                                    (uchar **)&local_98), ppVar20 = local_a0, iVar12 == 0))
            goto LAB_000558f0;
          }
          ppVar27 = local_d0;
          pIVar23 = local_d4;
          ppVar25 = local_d8;
          uVar3 = *(ushort *)(local_d8 + 2);
          uVar21 = *(uint *)(ppVar20 + 8);
          if (uVar21 <= *(int *)(local_d8 + 4) - (uint)uVar3 >> 3) {
            local_88 = CONCAT44(pIVar36,ppVar35);
            local_78 = 0x3f800000;
            local_80 = ppVar37;
            local_7c = iVar7;
            std::
            __hash_table<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>
            ::reserve((__hash_table<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>
                       *)&local_88,uVar21);
            ppVar25 = ppVar25 + uVar3;
            pvVar16 = *(void **)(this_00 + 0x140);
            if ((uint)(*(int *)(this_00 + 0x148) - (int)pvVar16 >> 3) < uVar21) {
              if (0x1fffffff < uVar21) {
                    /* WARNING: Subroutine does not return */
                abort();
              }
              __n = *(int *)(this_00 + 0x144) - (int)pvVar16;
              pvVar30 = operator_new(uVar21 << 3);
              if (0 < (int)__n) {
                __aeabi_memcpy8(pvVar30,pvVar16,__n);
              }
              *(void **)(this_00 + 0x140) = pvVar30;
              *(size_t *)(this_00 + 0x144) = (int)pvVar30 + __n;
              *(void **)(this_00 + 0x148) = (void *)((int)pvVar30 + uVar21 * 8);
              if (pvVar16 != (void *)0x0) {
                operator_delete(pvVar16);
              }
LAB_00054e50:
              local_128 = ppVar27;
              pIStack_12c = pIVar23;
              ppVar20 = ppVar25 + uVar21 * 8;
              do {
                local_130 = ppVar25;
                if ((ppVar25 == (piecewise_construct_t *)0x0) ||
                   (((pIStack_12c != (IncFsFileMap *)0x0 &&
                     ((local_e8 = ppVar25 + 8, local_70 = ppVar25, ppVar25 < local_128 ||
                      (local_128 + 0x1000 < local_e8)))) &&
                    (iVar12 = incfs::IncFsFileMap::Verify
                                        (pIStack_12c,(uchar **)&local_70,(uchar **)&local_e8,
                                         (uchar **)&local_128), iVar12 == 0)))) {
                  iVar12 = android::base::ShouldLog(4,0);
                  if (iVar12 != 0) {
                    puVar9 = (undefined4 *)__errno();
                    uVar26 = *puVar9;
                    android::base::LogMessage::LogMessage
                              ((LogMessage *)&local_70,
                               "frameworks/base/libs/androidfw/LoadedArsc.cpp",0x2e5,4,0,0xffffffff)
                    ;
                    poVar10 = (ostream *)android::base::LogMessage::stream();
                    std::__put_character_sequence<char,std::char_traits<char>>
                              (poVar10,"NULL ResTable_staged_alias_entry record??",0x29);
                    android::base::LogMessage::~LogMessage((LogMessage *)&local_70);
                    *puVar9 = uVar26;
                  }
                  bVar34 = false;
                  *(undefined4 *)this = 0;
                  ppVar20 = local_80;
                  goto joined_r0x00054fca;
                }
                local_e8 = *(piecewise_construct_t **)(local_130 + 4);
                std::
                __hash_table<unsigned_int,std::hash<unsigned_int>,std::equal_to<unsigned_int>,std::allocator<unsigned_int>>
                ::__emplace_unique_key_args<unsigned_int,unsigned_int_const&>
                          ((uint *)&local_70,(uint *)&local_88);
                if ((char)local_6c == '\0') {
                  iVar12 = android::base::ShouldLog(4,0);
                  if (iVar12 != 0) {
                    puVar9 = (undefined4 *)__errno();
                    uVar26 = *puVar9;
                    android::base::LogMessage::LogMessage
                              ((LogMessage *)&local_f8,
                               "frameworks/base/libs/androidfw/LoadedArsc.cpp",0x2ea,4,0,0xffffffff)
                    ;
                    poVar10 = (ostream *)android::base::LogMessage::stream();
                    android::base::StringPrintf
                              ((char *)&local_70,
                               "Repeated finalized resource id \'%08x\' in staged aliases.",local_e8
                              );
                    std::operator<<(poVar10,(string *)&local_70);
                    if (((uint)local_70 & 1) != 0) {
                      operator_delete(local_68[0]);
                    }
                    android::base::LogMessage::~LogMessage((LogMessage *)&local_f8);
                    *puVar9 = uVar26;
                  }
                  *(undefined4 *)this = 0;
                  bVar34 = false;
                  ppVar20 = local_80;
                  goto joined_r0x00054fca;
                }
                p_Var18 = *(__59 **)(this_00 + 0x144);
                p_Var22 = *(__59 **)(this_00 + 0x148);
                local_70 = *(piecewise_construct_t **)local_130;
                if (p_Var18 < p_Var22) {
                  *(piecewise_construct_t **)p_Var18 = local_70;
                  *(piecewise_construct_t **)(p_Var18 + 4) = local_e8;
                  *(int *)(this_00 + 0x144) = *(int *)(this_00 + 0x144) + 8;
                }
                else {
                  std::
                  vector<std::pair<unsigned_int,unsigned_int>,std::allocator<std::pair<unsigned_int,unsigned_int>>>
                  ::__emplace_back_slow_path<unsigned_int&,unsigned_int&>
                            ((vector<std::pair<unsigned_int,unsigned_int>,std::allocator<std::pair<unsigned_int,unsigned_int>>>
                              *)(this_00 + 0x140),(uint *)&local_70,(uint *)&local_e8);
                  p_Var22 = extraout_r2_00;
                }
                ppVar25 = local_130 + 8;
                local_130 = ppVar25;
              } while (ppVar25 != ppVar20);
            }
            else {
              local_128 = ppVar27;
              pIStack_12c = pIVar23;
              p_Var22 = extraout_r2;
              local_130 = ppVar25;
              if (uVar21 != 0) goto LAB_00054e50;
            }
            std::
            __sort<android::LoadedPackage::Load(android::Chunk_const&,unsigned_int)::__59&,std::pair<unsigned_int,unsigned_int>*>
                      (*(pair **)(this_00 + 0x140),*(pair **)(this_00 + 0x144),p_Var22);
            piVar31 = *(int **)(this_00 + 0x140);
            piVar14 = *(int **)(this_00 + 0x144);
            piVar19 = piVar31;
            if (piVar31 != piVar14) {
              do {
                piVar31 = piVar19;
                piVar19 = piVar31 + 2;
                if (piVar19 == piVar14) goto LAB_00054fc4;
              } while (*piVar31 != *piVar19);
            }
            if (piVar31 == piVar14) {
LAB_00054fc4:
              bVar34 = true;
              ppVar20 = local_80;
            }
            else {
              iVar12 = android::base::ShouldLog(4,0);
              if (iVar12 != 0) {
                puVar9 = (undefined4 *)__errno();
                uVar26 = *puVar9;
                android::base::LogMessage::LogMessage
                          ((LogMessage *)&local_70,"frameworks/base/libs/androidfw/LoadedArsc.cpp",
                           0x2fa,4,0,0xffffffff);
                poVar10 = (ostream *)android::base::LogMessage::stream();
                android::base::StringPrintf
                          ((char *)&local_130,
                           "Repeated staged resource id \'%08x\' in staged aliases.",*piVar31);
                std::operator<<(poVar10,(string *)&local_130);
                if (((uint)local_130 & 1) != 0) {
                  operator_delete(local_128);
                }
                android::base::LogMessage::~LogMessage((LogMessage *)&local_70);
                *puVar9 = uVar26;
              }
              bVar34 = false;
              *(undefined4 *)this = 0;
              ppVar20 = local_80;
            }
joined_r0x00054fca:
            while (ppVar20 != (piecewise_construct_t *)0x0) {
              ppVar25 = *(piecewise_construct_t **)ppVar20;
              operator_delete(ppVar20);
              ppVar20 = ppVar25;
            }
            puVar6 = (uchar *)(piecewise_construct_t *)local_88;
            local_88 = local_88 & 0xffffffff00000000;
            if (puVar6 != (uchar *)0x0) {
              operator_delete(puVar6);
            }
            pvVar16 = local_c8;
            puVar9 = local_c0;
            if (bVar34) goto LAB_0005506a;
            goto joined_r0x0005578c;
          }
          iVar7 = android::base::ShouldLog(4,0);
          if (iVar7 == 0) goto LAB_00055784;
          puVar9 = (undefined4 *)__errno();
          uVar26 = *puVar9;
          this_03 = (LogMessage *)&local_88;
          android::base::LogMessage::LogMessage
                    (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x2db,4,0,0xffffffff);
          poVar10 = (ostream *)android::base::LogMessage::stream();
          uVar21 = 0x39;
          pcVar17 = "RES_TABLE_STAGED_ALIAS_TYPE is too small to hold entries.";
        }
        break;
      default:
        if (*(short *)local_d8 != 1) goto switchD_00054448_caseD_205;
        ppVar20 = local_d8;
        pIVar23 = local_d4;
        if (*(ushort *)(local_d8 + 2) < 8) {
          ppVar20 = (piecewise_construct_t *)0x0;
          pIVar23 = (IncFsFileMap *)0x0;
        }
        local_88 = CONCAT44(pIVar23,ppVar20);
        local_80 = local_d0;
        if (*(ushort *)(local_d8 + 2) < 8) {
          local_80 = (piecewise_construct_t *)0x0;
        }
        if (ppVar20 == (piecewise_construct_t *)0x0) {
LAB_000558b2:
          iVar7 = android::base::ShouldLog(4,0);
          if (iVar7 != 0) {
            puVar9 = (undefined4 *)__errno();
            uVar26 = *puVar9;
            this_03 = (LogMessage *)&local_a0;
            android::base::LogMessage::LogMessage
                      (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x1fd,4,0,0xffffffff)
            ;
            poVar10 = (ostream *)android::base::LogMessage::stream();
            uVar21 = 0x43;
            pcVar17 = "RES_STRING_POOL_TYPE is incomplete due to incremental installation.";
            break;
          }
          goto LAB_00055784;
        }
        ppVar25 = local_d8;
        if ((pIVar23 != (IncFsFileMap *)0x0) &&
           ((local_130 = ppVar20 + 8, local_a0 = ppVar20, ppVar20 < local_80 ||
            (local_80 + 0x1000 < local_130)))) {
          iVar12 = incfs::IncFsFileMap::Verify
                             (pIVar23,(uchar **)&local_a0,(uchar **)&local_130,(uchar **)&local_80);
          if (iVar12 == 0) goto LAB_000558b2;
          ppVar25 = (piecewise_construct_t *)local_88;
        }
        if (ppVar25 == (piecewise_construct_t *)(local_b0 + *(int *)(local_b0 + 0x10c))) {
          ppVar25 = local_d0;
          pIVar23 = local_d4;
          ppVar20 = local_d8;
          if (*(ushort *)(local_d8 + 2) < 0x1c) {
            ppVar20 = (piecewise_construct_t *)0x0;
            pIVar23 = (IncFsFileMap *)0x0;
            ppVar25 = (piecewise_construct_t *)0x0;
          }
          iVar12 = ResStringPool::setTo
                             (this_00,ppVar20,pIVar23,ppVar25,*(undefined4 *)(local_d8 + 4),0);
          if (iVar12 != 0) {
            iVar7 = android::base::ShouldLog(4,0);
            if (iVar7 != 0) {
              puVar9 = (undefined4 *)__errno();
              uVar26 = *puVar9;
              this_03 = (LogMessage *)&local_a0;
              android::base::LogMessage::LogMessage
                        (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x206,4,0,
                         0xffffffff);
              poVar10 = (ostream *)android::base::LogMessage::stream();
              uVar21 = 0x27;
              pcVar17 = "RES_STRING_POOL_TYPE for types corrupt.";
              break;
            }
            goto LAB_00055784;
          }
        }
        else {
          if (ppVar25 == (piecewise_construct_t *)(local_b0 + *(int *)(local_b0 + 0x114))) {
            ppVar25 = local_d0;
            pIVar23 = local_d4;
            ppVar20 = local_d8;
            if (*(ushort *)(local_d8 + 2) < 0x1c) {
              ppVar20 = (piecewise_construct_t *)0x0;
              pIVar23 = (IncFsFileMap *)0x0;
              ppVar25 = (piecewise_construct_t *)0x0;
            }
            iVar12 = ResStringPool::setTo
                               (this_00 + 0x5c,ppVar20,pIVar23,ppVar25,*(undefined4 *)(local_d8 + 4)
                                ,0);
            if (iVar12 == 0) goto LAB_0005506a;
            iVar7 = android::base::ShouldLog(4,0);
            if (iVar7 != 0) {
              puVar9 = (undefined4 *)__errno();
              uVar26 = *puVar9;
              this_03 = (LogMessage *)&local_a0;
              android::base::LogMessage::LogMessage
                        (this_03,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x20f,4,0,
                         0xffffffff);
              poVar10 = (ostream *)android::base::LogMessage::stream();
              uVar21 = 0x26;
              pcVar17 = "RES_STRING_POOL_TYPE for keys corrupt.";
              break;
            }
            goto LAB_00055784;
          }
          iVar12 = android::base::ShouldLog(3,0);
          if (iVar12 != 0) {
            puVar9 = (undefined4 *)__errno();
            uVar26 = *puVar9;
            android::base::LogMessage::LogMessage
                      ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x213
                       ,3,0,0xffffffff);
            poVar10 = (ostream *)android::base::LogMessage::stream();
            std::__put_character_sequence<char,std::char_traits<char>>
                      (poVar10,"Too many RES_STRING_POOL_TYPEs found in RES_TABLE_PACKAGE_TYPE.",
                       0x3f);
            android::base::LogMessage::~LogMessage((LogMessage *)&local_a0);
            *puVar9 = uVar26;
          }
        }
LAB_0005506a:
        bVar34 = local_50 == 0;
        if ((local_50 != 0) || (local_54 == 0)) goto LAB_000553ce;
        goto LAB_0005442c;
      }
      std::__put_character_sequence<char,std::char_traits<char>>(poVar10,pcVar17,uVar21);
      android::base::LogMessage::~LogMessage(this_03);
      *puVar9 = uVar26;
      goto LAB_00055784;
    }
LAB_000553ce:
    if (bVar34) {
LAB_000553f0:
      if (local_c0 != (undefined4 *)0x0) {
        puVar9 = local_c0;
        do {
          puVar15 = (ulonglong *)puVar9[3];
          local_130 = (piecewise_construct_t *)&local_70;
          local_88 = *puVar15;
          uVar26 = *(undefined4 *)((int)puVar15 + 0xc);
          uVar5 = puVar15[2];
          uVar33 = *(undefined4 *)((int)puVar15 + 0x14);
          *(undefined4 *)((int)puVar15 + 0xc) = 0;
          *(undefined4 *)(puVar15 + 2) = 0;
          *(undefined4 *)((int)puVar15 + 0x14) = 0;
          local_80 = *(piecewise_construct_t **)(puVar15 + 1);
          local_70 = (piecewise_construct_t *)CONCAT31(local_70._1_3_,(char)puVar9[2]);
          std::
          __hash_table<std::__hash_value_type<unsigned_char,android::TypeSpec>,std::__unordered_map_hasher<unsigned_char,std::__hash_value_type<unsigned_char,android::TypeSpec>,std::hash<unsigned_char>,true>,std::__unordered_map_equal<unsigned_char,std::__hash_value_type<unsigned_char,android::TypeSpec>,std::equal_to<unsigned_char>,true>,std::allocator<std::__hash_value_type<unsigned_char,android::TypeSpec>>>
          ::
          __emplace_unique_key_args<unsigned_char,std::piecewise_construct_t_const&,std::tuple<unsigned_char_const&>,std::tuple<>>
                    ((__hash_table<std::__hash_value_type<unsigned_char,android::TypeSpec>,std::__unordered_map_hasher<unsigned_char,std::__hash_value_type<unsigned_char,android::TypeSpec>,std::hash<unsigned_char>,true>,std::__unordered_map_equal<unsigned_char,std::__hash_value_type<unsigned_char,android::TypeSpec>,std::equal_to<unsigned_char>,true>,std::allocator<std::__hash_value_type<unsigned_char,android::TypeSpec>>>
                      *)&local_a0,(uchar *)(this_00 + 0xd4),local_130,(tuple *)&DAT_000358e8,
                     (tuple *)&local_130);
          ppVar35 = local_a0;
          *(piecewise_construct_t **)(local_a0 + 0x14) = local_80;
          pvVar16 = *(void **)(local_a0 + 0x18);
          *(piecewise_construct_t **)(local_a0 + 0xc) = (piecewise_construct_t *)local_88;
          *(undefined4 *)(local_a0 + 0x10) = local_88._4_4_;
          if (pvVar16 != (void *)0x0) {
            *(void **)(local_a0 + 0x1c) = pvVar16;
            operator_delete(pvVar16);
          }
          *(undefined4 *)(ppVar35 + 0x18) = uVar26;
          *(int *)(ppVar35 + 0x1c) = (int)uVar5;
          *(undefined4 *)(ppVar35 + 0x20) = uVar33;
          puVar9 = (undefined4 *)*puVar9;
        } while (puVar9 != (undefined4 *)0x0);
      }
      *(ResStringPool **)this = this_00;
      pvVar16 = local_c8;
      puVar9 = local_c0;
      this_00 = (ResStringPool *)0x0;
    }
    else {
      iVar7 = android::base::ShouldLog(4,0);
      if (iVar7 != 0) {
        puVar9 = (undefined4 *)__errno();
        uVar26 = *puVar9;
        android::base::LogMessage::LogMessage
                  ((LogMessage *)&local_a0,"frameworks/base/libs/androidfw/LoadedArsc.cpp",0x307,4,0
                   ,0xffffffff);
        poVar10 = (ostream *)android::base::LogMessage::stream();
        ChunkIterator::GetLastError();
        std::operator<<(poVar10,(string *)&local_88);
        if ((local_88 & 1) != 0) {
          operator_delete(local_80);
        }
        android::base::LogMessage::~LogMessage((LogMessage *)&local_a0);
        *puVar9 = uVar26;
      }
      uVar21 = 0;
      if (local_50 != 0) {
        uVar21 = local_4c & 0xff;
      }
      if (local_50 == 0 || uVar21 == 0) goto LAB_000553f0;
LAB_00055784:
      *(undefined4 *)this = 0;
      pvVar16 = local_c8;
      puVar9 = local_c0;
    }
joined_r0x0005578c:
    while (puVar9 != (void *)0x0) {
      pvVar30 = (void *)puVar9[3];
      pvVar32 = (void *)*puVar9;
      puVar9[3] = 0;
      local_c8 = pvVar16;
      if (pvVar30 != (void *)0x0) {
        pvVar16 = *(void **)((int)pvVar30 + 0xc);
        if (pvVar16 != (void *)0x0) {
          *(void **)((int)pvVar30 + 0x10) = pvVar16;
          operator_delete(pvVar16);
        }
        operator_delete(pvVar30);
      }
      operator_delete(puVar9);
      pvVar16 = local_c8;
      puVar9 = pvVar32;
    }
    local_c8 = (void *)0x0;
    if (pvVar16 != (void *)0x0) {
      operator_delete(pvVar16);
    }
    if (this_00 == (ResStringPool *)0x0) goto LAB_00055a84;
  }
  pvVar16 = (void *)~LoadedPackage((LoadedPackage *)this_00);
  operator_delete(pvVar16);
LAB_00055a84:
  iVar7 = atrace_get_enabled_tags();
  if (iVar7 << 0x12 < 0) {
    atrace_end_body();
  }
  if (__stack_chk_guard != local_3c) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

