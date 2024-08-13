void confronto()
{
    gStyle->SetTitleFontSize(0.025);

    Double_t fermi_r{5.6474};
    Double_t fermi_w{5.5563};

    Double_t sn1_fermi_r{5.6486};
    Double_t sn1_fermi_w{5.5566};

    Double_t sn2_fermi_r{5.6500};
    Double_t sn2_fermi_w{5.5572};

    Double_t sn5_fermi_r{5.6541};
    Double_t sn5_fermi_w{5.5581};

    Double_t sn10_fermi_r{5.6609};
    Double_t sn10_fermi_w{5.5602};

    Double_t te1_fermi_r{5.6427};
    Double_t te1_fermi_w{5.5529};

    Double_t te2_fermi_r{5.6381};
    Double_t te2_fermi_w{5.5495};

    Double_t te5_fermi_r{5.6247};
    Double_t te5_fermi_w{5.5391};

    Double_t te10_fermi_r{5.6036};
    Double_t te10_fermi_w{5.5195};

    Double_t ymax{0.5};
    Double_t ymin{-0.5};

    Int_t n_points{128};

    TGraph *g = new TGraph("kagome_bands_new.dat");

    for (Int_t i{}; i < g->GetN(); i++)
    {
        Double_t y = g->GetPointY(i) + fermi_w - fermi_r;
        g->SetPointY(i, y);
    }

    g->SetLineColor(4);
    g->SetLineWidth(1);
    g->GetYaxis()->SetRangeUser(-2, 2);
    // g->GetXaxis()->SetRangeUser(0, 3.92617);
    g->GetYaxis()->SetTitle("Energy (eV)");
    g->SetTitle("CsV_{3}Sb_{5}");

    TGraph *sn1 = new TGraph("kagome_Sn_1_conf.dat");

    Double_t G = g->GetPointX(0);
    Double_t M = g->GetPointX(n_points);
    Double_t K = g->GetPointX(2 * n_points);
    Double_t G2 = g->GetPointX(3 * n_points);
    Double_t A = g->GetPointX(4 * n_points);
    Double_t L = g->GetPointX(5 * n_points);
    Double_t H = g->GetPointX(6 * n_points);
    Double_t A2 = g->GetPointX(7 * n_points);

    /*l1->SetLineColor(14);
    l2->SetLineColor(14);
    l3->SetLineColor(14);
    l4->SetLineColor(14);
    l5->SetLineColor(14);
    l6->SetLineColor(14);
    l7->SetLineColor(14);
    l8->SetLineColor(14);*/

    TLine *l = new TLine(0, 0, A2, 0);
    l->SetLineColor(kRed);
    l->SetLineStyle(2);

    for (Int_t i{}; i < sn1->GetN(); i++)
    {
        Double_t y = sn1->GetPointY(i) + sn1_fermi_w - sn1_fermi_r;
        sn1->SetPointY(i, y);
    }

    sn1->SetLineColor(4);
    sn1->SetLineWidth(1);
    // sn1->GetYaxis()->SetRangeUser(-2, 2);
    //  sn05->GetXaxis()->SetRangeUser(0, 3.92617);
    // sn1->GetYaxis()->SetTitle("Energy (eV)");
    // sn1->SetTitle("Drogaggio all'1% di Sn");

    TGraph *sn2 = new TGraph("kagome_Sn_2_conf.dat");

    for (Int_t i{}; i < sn2->GetN(); i++)
    {
        Double_t y = sn2->GetPointY(i) + sn2_fermi_w - sn2_fermi_r;
        sn2->SetPointY(i, y);
    }

    sn2->SetLineColor(4);
    sn2->SetLineWidth(1);
    // sn2->GetYaxis()->SetRangeUser(-2, 2);
    //  sn1->GetXaxis()->SetRangeUser(0, 3.92617);
    // sn2->GetYaxis()->SetTitle("Energy (eV)");
    // sn2->SetTitle("Drogaggio al 2% di Sn");

    TGraph *sn5 = new TGraph("kagome_Sn_5_conf.dat");

    for (Int_t i{}; i < sn5->GetN(); i++)
    {
        Double_t y = sn5->GetPointY(i) + sn5_fermi_w - sn5_fermi_r;
        sn5->SetPointY(i, y);
    }

    sn5->SetLineColor(4);
    sn5->SetLineWidth(1);
    // sn5->GetYaxis()->SetRangeUser(-2, 2);
    //  sn15->GetXaxis()->SetRangeUser(0, 3.92617);
    // sn5->GetYaxis()->SetTitle("Energy (eV)");
    // sn5->SetTitle("Drogaggio al 5% di Sn");

    TGraph *sn10 = new TGraph("kagome_Sn_10_conf.dat");

    for (Int_t i{}; i < sn10->GetN(); i++)
    {
        Double_t y = sn10->GetPointY(i) + sn10_fermi_w - sn10_fermi_r;
        sn10->SetPointY(i, y);
    }

    sn10->SetLineColor(4);
    sn10->SetLineWidth(1);
    // sn10->GetYaxis()->SetRangeUser(-2, 2);
    //  sn2->GetXaxis()->SetRangeUser(0, 3.92617);
    // sn10->GetYaxis()->SetTitle("Energy (eV)");
    // sn10->SetTitle("Drogaggio al 10% di Sn");

    TGraph *Te1 = new TGraph("kagome_Te_1_conf.dat");

    for (Int_t i{}; i < Te1->GetN(); i++)
    {
        Double_t y = Te1->GetPointY(i) + te1_fermi_w - te1_fermi_r;
        Te1->SetPointY(i, y);
    }

    Te1->SetLineColor(4);
    Te1->SetLineWidth(1);
    // Te1->GetYaxis()->SetRangeUser(-2, 2);
    //  Te05->GetXaxis()->SetRangeUser(0, 3.92617);
    // Te1->GetYaxis()->SetTitle("Energy (eV)");
    // Te1->SetTitle("Drogaggio all'1% di Te");

    TGraph *Te2 = new TGraph("kagome_Te_2_conf.dat");

    for (Int_t i{}; i < Te2->GetN(); i++)
    {
        Double_t y = Te2->GetPointY(i) + te2_fermi_w - te2_fermi_r;
        Te2->SetPointY(i, y);
    }

    Te2->SetLineColor(4);
    Te2->SetLineWidth(1);
    // Te2->GetYaxis()->SetRangeUser(-2, 2);
    //  Te1->GetXaxis()->SetRangeUser(0, 3.92617);
    // Te2->GetYaxis()->SetTitle("Energy (eV)");
    // Te2->SetTitle("Drogaggio al 2% di Te");

    TGraph *Te5 = new TGraph("kagome_Te_5_conf.dat");

    for (Int_t i{}; i < Te5->GetN(); i++)
    {
        Double_t y = Te5->GetPointY(i) + te5_fermi_w - te5_fermi_r;
        Te5->SetPointY(i, y);
    }

    Te5->SetLineColor(4);
    Te5->SetLineWidth(1);
    // Te5->GetYaxis()->SetRangeUser(-2, 2);
    //  Te15->GetXaxis()->SetRangeUser(0, 3.92617);
    // Te5->GetYaxis()->SetTitle("Energy (eV)");
    // Te5->SetTitle("Drogaggio al 5% di Te");

    TGraph *Te10 = new TGraph("kagome_Te_10_conf.dat");

    for (Int_t i{}; i < Te10->GetN(); i++)
    {
        Double_t y = Te10->GetPointY(i) + te10_fermi_w - te10_fermi_r;
        Te10->SetPointY(i, y);
    }

    Te10->SetLineColor(4);
    Te10->SetLineWidth(1);
    // Te10->GetYaxis()->SetRangeUser(-2, 2);
    //  Te2->GetXaxis()->SetRangeUser(0, 3.92617);
    // Te10->GetYaxis()->SetTitle("Energy (eV)");
    // Te10->SetTitle("Drogaggio al 10% di Te");

    TMultiGraph *mg = new TMultiGraph();

    g->SetLineColor(13);
    sn1->SetLineColor(kGreen - 9);
    sn2->SetLineColor(kGreen - 4);
    sn5->SetLineColor(kGreen + 1);
    sn10->SetLineColor(kGreen + 3);
    Te1->SetLineColor(kBlue - 9);
    Te2->SetLineColor(kBlue - 4);
    Te5->SetLineColor(kBlue + 1);
    Te10->SetLineColor(kBlue + 3);

    g->SetMarkerColor(13);
    sn1->SetMarkerColor(kGreen - 9);
    sn2->SetMarkerColor(kGreen - 4);
    sn5->SetMarkerColor(kGreen + 1);
    sn10->SetMarkerColor(kGreen + 3);
    Te1->SetMarkerColor(kBlue - 9);
    Te2->SetMarkerColor(kBlue - 4);
    Te5->SetMarkerColor(kBlue + 1);
    Te10->SetMarkerColor(kBlue + 3);

    mg->Add(g);
    mg->Add(sn1);
    mg->Add(sn2);
    mg->Add(sn5);
    mg->Add(sn10);
    mg->Add(Te1);
    mg->Add(Te2);
    mg->Add(Te5);
    mg->Add(Te10);

    mg->GetYaxis()->SetRangeUser(ymin, ymax);
    mg->GetXaxis()->SetRangeUser(0, A2);
    mg->GetYaxis()->SetTitle("#font[132]{Energy (eV)}");
    mg->GetHistogram()->SetTitle("#font[132]{Verifica dell'effetto strutturale del drogaggio su CsV_{3}Sb_{5}}");
    mg->GetXaxis()->SetNdivisions(0);
    // mg->GetHistogram()->SetTitleFontSize(0.005);
    mg->GetYaxis()->SetLabelFont(132);

    /*TH1F* h = mg->GetHistogram();
    Int_t n1 =h->FindFixBin(G);
    Int_t n2 =h->FindFixBin(M);
    Int_t n3 =h->FindFixBin(K);
    Int_t n4 =h->FindFixBin(G2);
    Int_t n5 =h->FindFixBin(A);
    Int_t n6 =h->FindFixBin(L);
    Int_t n7 =h->FindFixBin(H);
    Int_t n8 =h->FindFixBin(A2);
    h->GetXaxis()->SetLabelSize(0.03);
    h->GetXaxis()->SetBinLabel(n1, "#Gamma");
    h->GetXaxis()->SetBinLabel(n2, "M");
    h->GetXaxis()->SetBinLabel(n3, "K");
    h->GetXaxis()->SetBinLabel(n4, "#Gamma");
    h->GetXaxis()->SetBinLabel(n5, "A");
    h->GetXaxis()->SetBinLabel(n6, "L");
    h->GetXaxis()->SetBinLabel(n7, "H");
    h->GetXaxis()->SetBinLabel(n8, "A");*/

    TGraph *rndm = new TGraph();
    rndm->SetLineColor(0);
    rndm->SetMarkerSize(0);
    rndm->SetMarkerStyle(0);
    rndm->SetMarkerColor(0);

    TLegend *leg = new TLegend(0.1, 0.9, 0.9, 0.95);

    leg->SetNColumns(9);

    leg->AddEntry(g, "#font[132]{CsV_{3}Sb_{5}}");
    leg->AddEntry(sn1, "#font[132]{1% di Sn}");
    leg->AddEntry(sn2, "#font[132]{2% di Sn}");
    leg->AddEntry(sn5, "#font[132]{5% di Sn}");
    leg->AddEntry(sn10, "#font[132]{10% di Sn}");
    leg->AddEntry(Te1, "#font[132]{1% di Te}");
    leg->AddEntry(Te2, "#font[132]{2% di Te}");
    leg->AddEntry(Te5, "#font[132]{5% di Te}");
    leg->AddEntry(Te10, "#font[132]{10%di Te}");

    leg->SetTextSize(0.02);

    Double_t G_sn_1 = sn1->GetPointX(0);
    Double_t M_sn_1 = sn1->GetPointX(n_points);
    Double_t K_sn_1 = sn1->GetPointX(2 * n_points);
    Double_t G2_sn_1 = sn1->GetPointX(3 * n_points);
    Double_t A_sn_1 = sn1->GetPointX(4 * n_points);
    Double_t L_sn_1 = sn1->GetPointX(5 * n_points);
    Double_t H_sn_1 = sn1->GetPointX(6 * n_points);
    Double_t A2_sn_1 = sn1->GetPointX(7 * n_points);

    Double_t G_sn_2 = sn2->GetPointX(0);
    Double_t M_sn_2 = sn2->GetPointX(n_points);
    Double_t K_sn_2 = sn2->GetPointX(2 * n_points);
    Double_t G2_sn_2 = sn2->GetPointX(3 * n_points);
    Double_t A_sn_2 = sn2->GetPointX(4 * n_points);
    Double_t L_sn_2 = sn2->GetPointX(5 * n_points);
    Double_t H_sn_2 = sn2->GetPointX(6 * n_points);
    Double_t A2_sn_2 = sn2->GetPointX(7 * n_points);

    Double_t G_sn_5 = sn5->GetPointX(0);
    Double_t M_sn_5 = sn5->GetPointX(n_points);
    Double_t K_sn_5 = sn5->GetPointX(2 * n_points);
    Double_t G2_sn_5 = sn5->GetPointX(3 * n_points);
    Double_t A_sn_5 = sn5->GetPointX(4 * n_points);
    Double_t L_sn_5 = sn5->GetPointX(5 * n_points);
    Double_t H_sn_5 = sn5->GetPointX(6 * n_points);
    Double_t A2_sn_5 = sn5->GetPointX(7 * n_points);

    Double_t G_sn_10 = sn10->GetPointX(0);
    Double_t M_sn_10 = sn10->GetPointX(n_points);
    Double_t K_sn_10 = sn10->GetPointX(2 * n_points);
    Double_t G2_sn_10 = sn10->GetPointX(3 * n_points);
    Double_t A_sn_10 = sn10->GetPointX(4 * n_points);
    Double_t L_sn_10 = sn10->GetPointX(5 * n_points);
    Double_t H_sn_10 = sn10->GetPointX(6 * n_points);
    Double_t A2_sn_10 = sn10->GetPointX(7 * n_points);

    Double_t G_Te_1 = Te1->GetPointX(0);
    Double_t M_Te_1 = Te1->GetPointX(n_points);
    Double_t K_Te_1 = Te1->GetPointX(2 * n_points);
    Double_t G2_Te_1 = Te1->GetPointX(3 * n_points);
    Double_t A_Te_1 = Te1->GetPointX(4 * n_points);
    Double_t L_Te_1 = Te1->GetPointX(5 * n_points);
    Double_t H_Te_1 = Te1->GetPointX(6 * n_points);
    Double_t A2_Te_1 = Te1->GetPointX(7 * n_points);

    Double_t G_Te_2 = Te2->GetPointX(0);
    Double_t M_Te_2 = Te2->GetPointX(n_points);
    Double_t K_Te_2 = Te2->GetPointX(2 * n_points);
    Double_t G2_Te_2 = Te2->GetPointX(3 * n_points);
    Double_t A_Te_2 = Te2->GetPointX(4 * n_points);
    Double_t L_Te_2 = Te2->GetPointX(5 * n_points);
    Double_t H_Te_2 = Te2->GetPointX(6 * n_points);
    Double_t A2_Te_2 = Te2->GetPointX(7 * n_points);

    Double_t G_Te_5 = Te5->GetPointX(0);
    Double_t M_Te_5 = Te5->GetPointX(n_points);
    Double_t K_Te_5 = Te5->GetPointX(2 * n_points);
    Double_t G2_Te_5 = Te5->GetPointX(3 * n_points);
    Double_t A_Te_5 = Te5->GetPointX(4 * n_points);
    Double_t L_Te_5 = Te5->GetPointX(5 * n_points);
    Double_t H_Te_5 = Te5->GetPointX(6 * n_points);
    Double_t A2_Te_5 = Te5->GetPointX(7 * n_points);

    Double_t G_Te_10 = Te10->GetPointX(0);
    Double_t M_Te_10 = Te10->GetPointX(n_points);
    Double_t K_Te_10 = Te10->GetPointX(2 * n_points);
    Double_t G2_Te_10 = Te10->GetPointX(3 * n_points);
    Double_t A_Te_10 = Te10->GetPointX(4 * n_points);
    Double_t L_Te_10 = Te10->GetPointX(5 * n_points);
    Double_t H_Te_10 = Te10->GetPointX(6 * n_points);
    Double_t A2_Te_10 = Te10->GetPointX(7 * n_points);

    mg->GetXaxis()->SetRangeUser(0, A2_Te_10);

    TLine *l1 = new TLine(G, ymin, G, ymax);
    TLine *l2 = new TLine(M, ymin, M, ymax);
    TLine *l3 = new TLine(K, ymin, K, ymax);
    TLine *l4 = new TLine(G2, ymin, G2, ymax);
    TLine *l5 = new TLine(A, ymin, A, ymax);
    TLine *l6 = new TLine(L, ymin, L, ymax);
    TLine *l7 = new TLine(H, ymin, H, ymax);
    TLine *l8 = new TLine(A2_Te_10, ymin, A2_Te_10, ymax);

    TLegend *Gamma = new TLegend(0.095, 0.05, 0.12, 0.098);
    Gamma->AddEntry(rndm, "#Gamma");
    Gamma->SetBorderSize(0);

    TLegend *m = new TLegend(0.198, 0.05, 0.323, 0.098);
    m->AddEntry(rndm, "#font[132]{M}");
    m->SetBorderSize(0);

    TLegend *k = new TLegend(0.278, 0.05, 0.403, 0.098);
    k->AddEntry(rndm, "#font[132]{K}");
    k->SetBorderSize(0);

    TLegend *Gamma2 = new TLegend(0.437, 0.05, 0.562, 0.098);
    Gamma2->AddEntry(rndm, "#Gamma");
    Gamma2->SetBorderSize(0);

    TLegend *a = new TLegend(0.5, 0.05, 0.625, 0.098);
    a->AddEntry(rndm, "#font[132]{A}");
    a->SetBorderSize(0);

    TLegend *lp = new TLegend(0.637, 0.05, 0.762, 0.098);
    lp->AddEntry(rndm, "#font[132]{L}");
    lp->SetBorderSize(0);

    TLegend *h = new TLegend(0.7125, 0.05, 0.8375, 0.098);
    h->AddEntry(rndm, "#font[132]{H}");
    h->SetBorderSize(0);

    TLegend *a2 = new TLegend(0.865, 0.05, 0.99, 0.098);
    a2->AddEntry(rndm, "#font[132]{A}");
    a2->SetBorderSize(0);

    TCanvas *c_multi = new TCanvas();

    mg->Draw("AL");
    // h->Draw("SAME");
    l->Draw();
    l1->Draw();
    l2->Draw();
    l3->Draw();
    l4->Draw();
    l5->Draw();
    l6->Draw();
    l7->Draw();
    l8->Draw();
    leg->Draw("SAME");
    Gamma->Draw("SAME");
    m->Draw("SAME");
    k->Draw("SAME");
    Gamma2->Draw("SAME");
    a->Draw("SAME");
    lp->Draw("SAME");
    h->Draw("SAME");
    a2->Draw("SAME");

    cout << "K-POINTS" << '\n'
         << '\n';

    cout << "Kagome non drogato: " << '\n';
    cout << "#Gamma = " << G << '\n';
    cout << "M = " << M << '\n';
    cout << "K = " << K << '\n';
    cout << "#Gamma = " << G2 << '\n';
    cout << "A = " << A << '\n';
    cout << "L = " << L << '\n';
    cout << "H = " << H << '\n';
    cout << "A = " << A2 << '\n';
    cout << '\n';

    cout << "1% di Sn: " << '\n';
    cout << "#Gamma = " << G_sn_1 << '\n';
    cout << "M = " << M_sn_1 << '\n';
    cout << "K = " << K_sn_1 << '\n';
    cout << "#Gamma = " << G2_sn_1 << '\n';
    cout << "A = " << A_sn_1 << '\n';
    cout << "L = " << L_sn_1 << '\n';
    cout << "H = " << H_sn_1 << '\n';
    cout << "A = " << A2_sn_1 << '\n';
    cout << '\n';

    cout << "2% di Sn: " << '\n';
    cout << "#Gamma = " << G_sn_2 << '\n';
    cout << "M = " << M_sn_2 << '\n';
    cout << "K = " << K_sn_2 << '\n';
    cout << "#Gamma = " << G2_sn_2 << '\n';
    cout << "A = " << A_sn_2 << '\n';
    cout << "L = " << L_sn_2 << '\n';
    cout << "H = " << H_sn_2 << '\n';
    cout << "A = " << A2_sn_2 << '\n';
    cout << '\n';

    cout << "5% di Sn: " << '\n';
    cout << "#Gamma = " << G_sn_5 << '\n';
    cout << "M = " << M_sn_5 << '\n';
    cout << "K = " << K_sn_5 << '\n';
    cout << "#Gamma = " << G2_sn_5 << '\n';
    cout << "A = " << A_sn_5 << '\n';
    cout << "L = " << L_sn_5 << '\n';
    cout << "H = " << H_sn_5 << '\n';
    cout << "A = " << A2_sn_5 << '\n';
    cout << '\n';

    cout << "10% di Sn: " << '\n';
    cout << "#Gamma = " << G_sn_10 << '\n';
    cout << "M = " << M_sn_10 << '\n';
    cout << "K = " << K_sn_10 << '\n';
    cout << "#Gamma = " << G2_sn_10 << '\n';
    cout << "A = " << A_sn_10 << '\n';
    cout << "L = " << L_sn_10 << '\n';
    cout << "H = " << H_sn_10 << '\n';
    cout << "A = " << A2_sn_10 << '\n';
    cout << '\n';

    cout << "1% di Te: " << '\n';
    cout << "#Gamma = " << G_Te_1 << '\n';
    cout << "M = " << M_Te_1 << '\n';
    cout << "K = " << K_Te_1 << '\n';
    cout << "#Gamma = " << G2_Te_1 << '\n';
    cout << "A = " << A_Te_1 << '\n';
    cout << "L = " << L_Te_1 << '\n';
    cout << "H = " << H_Te_1 << '\n';
    cout << "A = " << A2_Te_1 << '\n';
    cout << '\n';

    cout << "2% di Te: " << '\n';
    cout << "#Gamma = " << G_Te_2 << '\n';
    cout << "M = " << M_Te_2 << '\n';
    cout << "K = " << K_Te_2 << '\n';
    cout << "#Gamma = " << G2_Te_2 << '\n';
    cout << "A = " << A_Te_2 << '\n';
    cout << "L = " << L_Te_2 << '\n';
    cout << "H = " << H_Te_2 << '\n';
    cout << "A = " << A2_Te_2 << '\n';
    cout << '\n';

    cout << "5% di Te: " << '\n';
    cout << "#Gamma = " << G_Te_5 << '\n';
    cout << "M = " << M_Te_5 << '\n';
    cout << "K = " << K_Te_5 << '\n';
    cout << "#Gamma = " << G2_Te_5 << '\n';
    cout << "A = " << A_Te_5 << '\n';
    cout << "L = " << L_Te_5 << '\n';
    cout << "H = " << H_Te_5 << '\n';
    cout << "A = " << A2_Te_5 << '\n';
    cout << '\n';

    cout << "10% di Te: " << '\n';
    cout << "#Gamma = " << G_Te_10 << '\n';
    cout << "M = " << M_Te_10 << '\n';
    cout << "K = " << K_Te_10 << '\n';
    cout << "#Gamma = " << G2_Te_10 << '\n';
    cout << "A = " << A_Te_10 << '\n';
    cout << "L = " << L_Te_10 << '\n';
    cout << "H = " << H_Te_10 << '\n';
    cout << "A = " << A2_Te_10 << '\n';
    cout << '\n';
}